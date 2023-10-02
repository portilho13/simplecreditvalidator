def main():
    creditcard = input("Enter Creditcard number: ")
    if (isValid(creditcard)):
        print(getType(creditcard))

def isValid(creditcard):
    sum = 0
    for i in range(len(creditcard)):
        digit = int(creditcard[i])
        if len(creditcard) % 2 == 0:
            if i % 2 == 0:
                digit *= 2
                if digit > 9:
                    digit -= 9
                sum += digit
            else:
                sum += digit
        else:
            if digit % 2 != 0:
                digit *= 2
                if digit > 9:
                    digit -= 9
                sum += digit
            else:
                sum += digit
    return sum % 10 == 0
    
def getType(creditcard):
    count = len(creditcard)
    n = int(creditcard[:2])
    if (count == 16 or count == 13) and (40 <= n <= 49):
        return "VISA"
    elif count == 16 and (51 <= n <= 55):
        return "MASTERCARD"
    elif count  == 15 and (n == 34 or n == 37):
        return "AMEX"
    else:
        return "INVALID"
if __name__ == "__main__":
    main()