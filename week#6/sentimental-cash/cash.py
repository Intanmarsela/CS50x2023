from cs50 import get_float

def main ():
    owed = get_float("Change owed: ")
    while owed < 0:
        owed = get_float("Change owed: ")

    quarter = cal_coins(owed, 0.25)
    owed = update_owed(owed, quarter, 0.25)

    dimes = cal_coins(owed, 0.10)
    owed = update_owed(owed, dimes, 0.10)

    nickels = cal_coins(owed, 0.05)
    owed = update_owed(owed, nickels, 0.05)

    pennies = cal_coins(owed, 0.01)

    sum = quarter + dimes + nickels + pennies
    print(f"{sum} coins")

def cal_coins(owed, value):
    coins = owed // value
    return coins

def update_owed (owed, coins, value):
    return round (owed - (coins * value), 2)

main()
