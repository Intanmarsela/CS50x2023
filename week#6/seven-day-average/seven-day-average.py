import csv
import requests
import time


def main():
    # Read NYTimes Covid Database
    download = requests.get(
        "https://raw.githubusercontent.com/nytimes/covid-19-data/master/us-states.csv"
    )
    decoded_content = download.content.decode("utf-8")
    file = decoded_content.splitlines()
    reader = csv.DictReader(file)

    # Construct 14 day lists of new cases for each states
    new_cases = calculate(reader)

    # Create a list to store selected states
    states = []
    print("Choose one or more states to view average COVID cases.")
    print("Press enter when done.\n")

    while True:
        state = input("State: ")
        if state in new_cases:
            states.append(state)
        if len(state) == 0:
            break

    print(f"\nSeven-Day Averages")

    # Print out 7-day averages for this week vs last week
    comparative_averages(new_cases, states)


# TODO: Create a dictionary to store 14 most recent days of new cases by state
def calculate(reader):
    sum_cases = dict()
    new_cases = dict()

    for value in reader:
        state = str(value["state"])
        cases = int(value["cases"])

        if state not in sum_cases:
            sum_cases[state] = list()

        sum_cases[state].append(cases)

    for state, cases in sum_cases.items():
        if state not in new_cases:
            new_cases[state] = list()
            new_cases[state].append(cases[0])
        for i in range (1, len(cases)):
            diff = cases[i] - cases[i - 1]
            new_cases[state].append(diff)

    return new_cases


# TODO: Calculate and print out seven day average for given state
def comparative_averages(new_cases, states):
    for state in states:
        values = new_cases[state]
        avg = list()
        total = 0
        start = 0
        finish = 7
        end = len(values)

        while finish <= end:
            summ = sum(values[start: finish + 1])
            avgs = int(summ / 7)
            avg.append(avgs)
            start += 1
            finish += 1

        size = len(avg)
        inc = (avg[size - 1] - avg[size - 2]) / avg[size - 1]
        print(f"{state} had a 7-day average of {avgs} and an increase of {inc:.2f}%.")


main()
