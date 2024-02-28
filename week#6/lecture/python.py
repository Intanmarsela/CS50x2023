from cs50 import get_string
print("hello, world")

answer = get_string("what's your name? ")  #python will know that answer is a string without declaring its a string.
print ("hello, "+ answer) #Concatenation refers to the process of combining two or more strings into a single string
#in line 5 concatenation is done using '+' operator.

answer = get_string("What's your name? ")
print(f"hello, {answer}") # 'f' is a format string or fstring

"""
line 8 and line 9 are another better way to interpolating answer.
In computer science and programming, the term string interpolation is often used.
String interpolation is the process of evaluating a string literal containing one or more placeholders,
and then replacing those placeholders with their corresponding values.
"""

