using System;
using System.Globalization;
namespace Credit
{
    class Credit {         
        static void Main(string[] args)
        {
            Console.WriteLine("Enter Card Number: ");
            string cardnumber = Console.ReadLine();
            int count = cardnumber.Length;
            if (isValid(cardnumber)) {
                Console.WriteLine(getType(cardnumber));
            }
        }
        static bool isValid(string cardnumber)
        {
            int sum = 0;
            for (int i = 0; i < cardnumber.Length; i++) {
                int digit = int.Parse(cardnumber[i].ToString());
                if (cardnumber.Length % 2 == 0) {
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
        static string getType(string cardnumber)
        {
            int count = cardnumber.Length;
            int n = int.Parse(cardnumber.Substring(0, 2));
            if ((count == 16 || count == 13) && (40 <= n && n <= 49)) {
                return "VISA";
            } else if (count == 16 && (51 <= n && n <= 55)) {
                return "MASTERCARD";
            } else if (count == 15 && (n == 34 || n == 37)) {
                return "AMEX";
            } else {
                return "INVALID";
            }
        }
    }
}