"""
data types in Pyhton : bool, float, int, str (string).
We dont need "long" and "double" anymore, bc int and float already using more bytes in it.
So we dont need to worry about it anymore.

New data types in Python are; range, list, tuple, dict, set.
"""

#Dictionary
# Words in dictionary
'''
words = set()


def check(word):
    """Return true if word is in dictionary else false"""
    if word.lower() in words: #this will convert all the word into lower case
        return True
    else:
        return False


def load(dictionary):
    """Load dictionary into memory, returning true if successful else false"""
    file = open(dictionary, "r") #read mode
    for line in file:
        word = line.rstrip() #rstrip is reverse strip, is get rid of the /n.
        words.add(word)
    file.close()
    return True


def size():
    """Returns number of words in dictionary if loaded else 0 if not yet loaded"""
    return len(words)


def unload():
    """Unloads dictionary from memory, returning true if successful else false"""
    return True #this function will free all the memory for you.
'''

'''
However, speed is a tradeoff. Because C allows you, the programmer,
to make decisions about memory management, it may run faster than Python
depending on your code. While C only runs your lines of code,
Python runs all the code that comes under the hood with it when you call Python's built-in functions.
'''

