from cs50 import get_int

height = get_int("Height: ")

while height <= 0 or height >= 9:
    height = get_int("Height: ")

for i in range(height):
    j = height
    while (j > i + 1):
        print (" ", end="")
        j -= 1
    for k in range(i + 1):
        print("#", end="")
    print()
