import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":

        # TODO:Add the user's entry into the database
        name = request.form.get("Name")
        month = request.form.get("Month")
        day = request.form.get("Date")

        db.execute("INSERT INTO birthdays(name, month, day) VALUES(?, ?, ?)", name, month, day)
        return redirect("/")
    if request.method =="GET":
        Del_name = request.args.get("Del_Name")
        Del_month = request.args.get("Del_Month")
        Del_day = request.args.get("Del_Date")

        if Del_name and Del_month and Del_day:
            db.execute("DELETE FROM birthdays WHERE name = ? AND month = ? AND day = ?", Del_name, Del_month, Del_day)

        # TODO: Display the entries in the database on index.html
        birthdays = db.execute("SELECT * FROM birthdays")
        return render_template("index.html", birthdays=birthdays)



