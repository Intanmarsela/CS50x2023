from cs50 import get_string


def main():
    text = get_string("Text: ")
    length = len(text)
    print (f"length {length}")
    words = 1
    letters = 0
    sentences = 0
    end_sentences = ['!', '?', '.']
    for i in range(length):
        if text[i].lower().isalpha():
            letters += 1
        if text[i].isspace():
            words += 1
        if text[i] in end_sentences:
            sentences += 1

    L = letters / words*100
    S = sentences / words*100
    index = round((0.0588 * L)- (0.296 * S) - 15.8)
    if index >= 16:
        print("Grade 16+")
    elif index < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {index}")

main()
