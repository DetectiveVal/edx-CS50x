# TODO
from cs50 import get_string


def main():
    words = 1
    sentences = 0
    letters = 0

    text = get_string("Enter your text: ")
    for i in text:
        if i == " ":
            words += 1
        elif i in {".", "?", "!"}:
            sentences += 1
        elif i.isalpha():
            letters += 1
    l = letters / words * 100
    s = sentences / words * 100

    coleman = round(0.0588 * l - 0.296 * s - 15.8)
    print(f"{coleman}-{words}- {letters}-{sentences}-{l}-{s}")
    if coleman < 1:
        print("Before Grade 1")
    elif coleman >= 1 and coleman <= 16:
        print(f"Grade {int(coleman)}")
    else:
        print("Grade 16+")


if __name__ == "__main__":
    main()