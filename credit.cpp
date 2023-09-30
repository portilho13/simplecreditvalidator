#include <stdio.h>
#include <iostream>
#include <string>

bool isValid(long cardnumber);
int getType(long cardnumber, int count);

int main() {
    long cardnumber;
    printf("Credit cardnumber: ");
    scanf("%li", &cardnumber);


    int count = 0;

    for (int i = 0; i < (std::to_string(cardnumber)).length(); i++) {
        count ++;
    }
    if (isValid(cardnumber)) {
        getType(cardnumber, count);
    }
    return 0;
}

bool isValid(long cardnumber) {
    std::string cardNumber = std::to_string(cardnumber);
    int sum = 0;
    int length = cardNumber.length();
    for (int i = 0; i < length; i++) {
        int digit = cardNumber[i] - '0';
        if (length % 2 == 0) {
            if (i % 2 == 0) {
                digit *= 2;
                if (digit > 9) {
                    digit -= 9;
                }
                sum += digit;
            } else {
                sum += digit;
            }
        } else {
            if (i % 2 != 0) {
                digit *= 2;
                if (digit > 9) {
                    digit -= 9;
                }
                sum += digit;
            } else {
                sum += digit;
            }
        }
    }
    return sum % 10 == 0;
}

int getType(long cardnumber, int count) {
    std::string cardNumber = std::to_string(cardnumber);
    int num = std::stoi(cardNumber.substr(0, 2));
    if ((count == 16 || count == 13) && (40 <= num && num <= 49)) {
        printf("VISA\n");
    } else if (count == 16 && (51 <= num && num <= 55)) {
        printf("MASTERCARD\n");
    } else if ((count == 15) && (num == 34 || num == 37)) {
        printf("AMEX\n");
    } else {
        printf("INVALID\n");
        return 1;
    }
    return 0;
}