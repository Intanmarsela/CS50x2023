import sys
import random
from pyfiglet import Figlet

figlet = Figlet()


def main():
    if len(sys.argv) < 2:
        font = random.choice(figlet.getFonts())
        thefiglet("Input: ", font)
    elif len(sys.argv) > 2 and sys.argv[1] in ["-f", "--font"] and sys.argv[2] in figlet.getFonts():
        font = sys.argv[2]
        thefiglet("Input: ", font)
    else:
        sys.exit("Invalid input")

def thefiglet (prompt, f):
    txt = input(prompt)
    figlet.setFont(font=f)
    print("output: ")
    print(figlet.renderText(txt))


main()




