#include <cs50.h>
#include <stdio.h>
#include <math.h>

/////////acnunciate functions
long get_cardnumber(void);
int get_count(long cardnumber);
int get_valid(long cardnumber, int count);
long get_type(long cardnumber, int count);

int main(void)
{
    long cardnumber = get_cardnumber();
    int count = get_count(cardnumber);
    int sum3 = get_valid(cardnumber, count);

    ///////////////final check
    if (sum3 % 10 == 0)
    {
        const char type = get_type(cardnumber, count);
    }
    else
    {
        printf("INVALID\n");
    }
}

////////////Get cardnumber
long get_cardnumber(void)
{
    long cardnumber;
    do
    {
        cardnumber = get_long("Number: ");
    }
    while (cardnumber < 15);
    return cardnumber;
}

//////////////Get count
int get_count(long cardnumber)
{
    int count = 0;
    do
    {
        cardnumber = cardnumber / 10;
        count++;
    }
    while (cardnumber > 0);
    return count;
}



/////////////Check Valid
int get_valid(long cardnumber, int count)
{

    int x;
    long cardnumber2 = cardnumber;
    int sum1 = 0;
    int j;
    ////////////Weird Math
    for (int i = 1; i <= count; i++)
    {
        cardnumber = cardnumber / 10;
        //////////// see if its even
        if (i % 2 == 0)
        {
        }
        else
        {
            x = (cardnumber % 10) * 2;
            if (x >= 10)
            {
                int o = x / 10;
                x = x % 10;
                sum1 += o;
                sum1 += x;
            }
            else
            {
                sum1 += x;
            };
        }
    }

    int sum2 = 0;
    //////////Weird math again
    for (int i = 0; i < count; i++)
    {
        ////////see if its even
        if (i % 2 == 0)
        {
            j = cardnumber2 % 10;
            sum2 = sum2 + j;
        }
        cardnumber2 = cardnumber2 / 10;
    }

    int sum3 = sum1 + sum2;
    return sum3;
}

///////////////Get type
long get_type(long cardnumber, int count)
{
    int exp = count - 2;
    int firsttwo = cardnumber / pow(10, exp);
    /////////Visa
    if ((count == 16 || count == 13) && (firsttwo >= 40 && firsttwo <= 49))
    {
        printf("VISA\n");
    }
    /////////Mastercard
    else if (count == 16 && (firsttwo >= 51 && firsttwo <= 55))
    {
        printf("MASTERCARD\n");;
    }
    /////////AMEX
    else if (count == 15 && (firsttwo == 34 || firsttwo == 37))
    {
        printf("AMEX\n");
    }

    else if (count < 13)
    {
        printf("INVALID\n");
    }
    else
    {
        printf("INVALID\n");
    }

    return firsttwo;
}