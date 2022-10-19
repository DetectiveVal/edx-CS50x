# TODO
def main():
    try:
        cardNum = int(input("Please enter your card number: "))
    except:
        print("Please make sure that you enter a number")
    cardNum = str(cardNum)
    if len(cardNum) in {13, 15, 16}:
        pass
    else:
        print("INVALID")
        exit()
    cardNumList = [int(x) for x in cardNum]
    cardNumList.reverse()
    if Luhn(cardNumList):
        if cardNum[0] == "3" and (cardNum[1] in {"4", "7"}):
            print("AMEX")
        elif cardNum[0] == "5" and (cardNum[1] in {"1", "2", "3", "4", "5"}):
            print("MASTERCARD")
        elif cardNum[0] == "4":
            print("VISA")
        else:
            print("INVALID")
    else:
        print("INVALID")


def Luhn(cardNumList):
    step1 = 0
    for i in range(1, len(cardNumList), 2):
        step = cardNumList[i] * 2
        step1 += (step//10) + (step % 10)
    for i in range(0, len(cardNumList), 2):
        step1 += cardNumList[i]
    if (step1 % 10) == 0:
        return True
    else:
        return False


if __name__ == "__main__":
    main()