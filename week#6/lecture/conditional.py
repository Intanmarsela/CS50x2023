# Conditionals, Boolean expressions, relational operators


from cs50 import get_int

# Prompt user for integers
x = get_int("What's x? ") #in C " int x = get_int("What's x? "); "
y = get_int("What's y? ") #in C " int y = get_int("What's y? "); "

# Compare integers                      # in C language
if x < y:                               # if (x < y)
    print("x is less than y")           # { printf("x is less than y\n"); }
elif x > y:                             # else if (x > y)
    print("x is greater than y")        # { printf("x is greater than y\n"); }
else:                                   # else
    print("x is equal to y")            # { printf("x is equal to y\n"); }

"""
in Pyhton we will not using alot of crazy syntax, but only semicolon " : ".
and the indetantion is automaticly done by python.
insted of else if, becomme elif.
"""

#Variable in C
counter = 0 #in Phyton we dont need the semicolon.
counter += 1 #same as in C.
#sadly counter++ is no longer in Pyhton.

#Loop
"""
in C we use for loop to go through smth, to counting smtg.
We could also do that in Pyhton like this
"""

# Demonstrates while loop
i = 0
while i < 3:
    print("meow1")
    i += 1

# Better design, it will give you one at a time.
for i in range(3):
    print("meow2")

#forever loop
'''
while(True):
    print("meow")

'''

# Abstraction with parameterization
def main():
    meow(3)


# Meow some number of times
def meow(n):
    for i in range(2):
        print("meow3")


main()



