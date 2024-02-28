import sys


class Jar:
    def __init__(self, capacity):
        if capacity < 0:
            raise ValueError
        else:
            self.capacity_ = capacity
            self.size_ = 0

    def __str__(self):
        if self.size_ == 0:
            return "Empty"
        else:
            return str ("🍪" * self.size_)

    def deposit(self, n):
        if self.size_ + n > self.capacity_:
            raise ValueError
        else:
            self.size_ += n

    def withdraw(self, n):
        if n > self.size_:
            raise ValueError
        else:
            self.size_ -= n

    @property
    def capacity(self):
        return self.capacity_

    @property
    def size(self):
        return self.size_

def main ():
    jar = Jar(15)
    print(jar)


    jar.deposit(2)
    print(jar)

    jar.withdraw(1) " Testing wether the withdraw is working "
    print(jar)

    print(str(jar.capacity)) " To check the capacity max of the cookie jar"


main()

