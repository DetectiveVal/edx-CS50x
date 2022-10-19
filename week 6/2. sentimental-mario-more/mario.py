# TODO
def main():
    while(True):
        try:
            height = int(input("Enter desired height: "))
        except:
            print("please make it an int")
            continue
        if height > 0 and height < 9:
            break
        else:
            print("Your entered height must be between 0-8")

    n = 0

    build(height, n)


def build(height, n):
    if height == 0 and n == (height + n):
        return
    build(height-1, n+1)
    print(" " * n, end="")
    for i in range(height):
        print("#", end="")
    print("  ", end="")
    for i in range(height):
        print("#", end="")

    print("\n", end="")


if __name__ == "__main__":
    main()