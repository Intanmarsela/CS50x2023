import sys

greeting = (input("Greeting: ")).lower().strip()

if greeting.startswith("hello"):
    print ("$0")
    sys.exit(0)
elif greeting.startswith("h"):
    print ("$20")
    sys.exit(0)
else:
    print("$100")
    sys.exit(0)



