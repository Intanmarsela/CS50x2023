import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    #Get user's stock and shares
    stocks = db.execute("SELECT symbol, SUM(shares) as total_shares FROM transactions WHERE user_id = :user_id GROUP BY symbol HAVING total_shares > 0",
                       user_id=session["user_id"])
    #Get user's cash balance
    cash = db.execute("SELECT cash FROM users WHERE id = :user_id", user_id=session["user_id"])[0]["cash"]

    #initialize variabel for total values
    total_value = cash
    grand_total = cash

    #iterate over stocks and add price and total value
    for stock in stocks:
        quote = lookup(stock["symbol"])
        stock["name"] = quote["name"]
        stock["price"] = quote["price"]
        stock["value"] = stock["price"] * stock["total_shares"]
        total_value += stock["value"]
        grand_total += stock["value"]

    return render_template("index.html", stocks=stocks, cash=cash, total_value=total_value, grand_total=grand_total)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    if request.method == "POST":
        symbol = request.form.get("symbol").upper()
        share = request.form.get("shares")
        if not symbol:
            return apology("Must provide symbol")
        elif not share or not share.isdigit() or int(share) <= 0:
            return apology("Must provide a positive integer number of share")

        quote = lookup(symbol)
        if quote is None:
            return apology("share is not found")

        price = quote["price"]
        total_cost = int(share) * price
        cash = db.execute("SELECT cash FROM users WHERE id = :user_id", user_id=session["user_id"])[0]["cash"]

        if cash < total_cost:
            return apology("Not enough cash")

        #update users table
        db.execute("UPDATE users SET cash = cash - :total_cost WHERE id = :user_id",
                   total_cost=total_cost, user_id=session["user_id"])

        #add the purchase to the history table
        db.execute("INSERT INTO transactions (user_id, symbol, shares, price) VALUES(:user_id, :symbol, :share, :price)",
                   user_id=session["user_id"], symbol=symbol, share=share, price=price)

        flash(f"Bought {share} shares of {symbol} for {usd(total_cost)}!")
        return redirect("/")

    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    #Query database for user's transactions, ordered by most recent first
    transactions = db.execute("SELECT * FROM transactions WHERE user_id = :user_id ORDER BY timestamp DESC",
                             user_id=session["user_id"])
    #Render history page with transactions
    return render_template("history.html", transactions=transactions)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    if request.method == "POST":
        quote = lookup(request.form.get("symbol"))
        if lookup(request.form.get("symbol")):
            return render_template("quote.html", quote=quote)
            #should print out the stock
        else:
            return apology("Stock doesn't exist", 400)

    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    session.clear()

    if request.method == "POST":

        pwd = request.form.get("password")
        rpwd = request.form.get("confirmation")
        user = request.form.get("username")

            #checking if form is blank.
        if not pwd:
            return apology("Password is blank", 400)
        if not rpwd:
            return apology("Retype-password is blank", 400)
        if not user:
            return apology("Username is blank", 400)

            #checking if both password and retype-password is match.
        if pwd != rpwd:
            return apology("Passwords do not match", 400)

            #check weather the userrname is taken or available.
        row = db.execute ("SELECT * FROM users WHERE username = ?", user)

        if len(row) != 0:
            return apology("Username is taken", 400)

            #inputing new user into database
        db.execute("INSERT INTO users (username, hash) VALUES(?, ?)", user, generate_password_hash(pwd))

            #Log user in.
            # Remember which user has logged in
        row = db.execute ("SELECT * FROM users WHERE username = ?", user)
        session["user_id"] = row[0]["id"]

        # Redirect user to home page
        return redirect("/")

        # if the user reach route via GET
    else:
         return render_template("register.html")



@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    #Get user's stock
    stocks = db.execute("SELECT symbol, SUM(shares) as total_shares FROM transactions WHERE user_id = :user_id GROUP BY symbol HAVING total_shares > 0 ",
                        user_id=session["user_id"])
    #if the user submits the form
    if request.method == "POST":
        symbol = request.form.get("symbol").upper()
        shares = request.form.get("shares")
        if not symbol:
            return apology ("Must provide symbol",400)
        elif not shares or not shares.isdigit() or int(shares) <= 0:
            return apology ("Must provide a positive integer number of shares", 400)
        else:
            shares = int(shares)

        for stock in stocks:
            if stock["symbol"] == symbol:
                if stock["total_shares"] < shares:
                    return apology("Not enough shares", 400)
                else:
                    quote = lookup(symbol)
                    if quote is None:
                        return apology("Symbol not found", 400)
                    price = quote["price"]
                    total_sale = shares * price

                    #Update users table
                    db.execute("UPDATE users SET cash = cash + :total_sale WHERE id = :user_id",
                               total_sale=total_sale, user_id=session["user_id"])

                    #Add the sale to the history table
                    db.execute("INSERT INTO transactions(user_id, symbol, shares, price) VALUES (:user_id, :symbol, :shares, :price)",
                               user_id=session["user_id"], symbol=symbol, shares=-shares, price=price)

                    flash(f"Sold {shares} shares of {symbol} for {usd(total_sale)}!")
                    return redirect("/")

        return apology("Symbol not found", 400)

    else:
        return render_template("sell.html", stocks=stocks)

@app.route("/change_password", methods=["GET", "POST"])
@login_required
def change_password():

    if request.method == "POST":
        user = request.form.get("username")
        pwd = request.form.get("password")
        np = request.form.get("newpass1")
        np2 = request.form.get("newpass2")

        if not user:
            return apology("Username is blank", 403)
        if not pwd:
            return apology("Password is blank", 403)
        if not np:
            return apology("Please type in new password", 403)
        if not np2:
            return apology("Please type in confirmation password", 403)

        if np != np2:
            return apology("New Password should be match", 403)

        rows = db.execute("SELECT * FROM users WHERE username = ?", user)

        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], pwd):
            return apology("invalid username and/or password", 403)

        db.execute("UPDATE users SET hash = ? WHERE username = ?", generate_password_hash(np), user)

        flash(f"Password has been updated!")
        return redirect("/change_password")

    else:
        return render_template("change_password.html")


@app.route("/add_cash", methods=["POST","GET"])
@login_required
def add_cash():
    if request.method == "POST":
        input = request.form.get("cash-value")
        if not input or int(input) < 100:
            return apology("Amount should be $100 or more", 404)
        db.execute("UPDATE users SET cash = cash + ? WHERE id = ?", input, session["user_id"])

        flash(f"${input} is added succesfully")
        return redirect("/add_cash")
    else:
        cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
        return render_template("add_cash.html", cash=cash)


