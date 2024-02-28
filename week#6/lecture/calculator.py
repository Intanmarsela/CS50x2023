"""
Calculator in C

#include <cs50.h>
#include <stdio.h>

int main (void)
{
 int x = get_int("x: ");
 int y = get_int("y: ");
 printf("%i\n", x + y);
}

"""

#Calculator in Pyton
#the main function is gone. what ever written in Python, it will just be effective and run from top to bottom.
from cs50 import get_int

x = get_int("x: ")
y = get_int("y: ")

print(x + y)


#better design, but it will be a string, not int.
#the input function will always return string.
x1 = input("x1: ")
y1 = input("y1: ")

print(x1 + y1)

#we could do typecasting by doing this.
#it is like converting the string to ASCII number. But easier :).
x2 = int (input("x2: "))
y2 = int (input("y2: "))

print(x2 + y2)

# Logical operators, using lists

from cs50 import get_string

# Prompt user to agree
s = get_string("Do you agree? ")

# Check whether agreed
if s.lower() in ["y", "yes"]: #lower is now build in s and making s value in that line is lower case.
    print("Agreed.")
elif s.lower() in ["n", "no"]:
    print("Not agreed.")

"""
We could optimising this value by calling the s first and initialize it with lower.

"""

# Logical operators, using lists

from cs50 import get_string

# Prompt user to agree
s = get_string("Do you agree? ")

s = s.lower()

# Check whether agreed
if s in ["y", "yes"]:
    print("Agreed.")
elif s in ["n", "no"]:
    print("Not agreed.")






