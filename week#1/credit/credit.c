//Checking weather a credit card is valid using Luhn's Algorithm.
//And returning the type of the credit card by checking the 2 first digits.

#include <cs50.h>
#include <stdio.h>
bool checksum (long credit);
int digit_counter (long credit);

int main(void)
{
    //Getting the credit card numbers
    long number = get_long ("Number: ");
    if ( !checksum (number))
    {
        printf ("INVALID\n");
        return 0;
    }
    long start = number; // 2 first digit
    while(start > 100)
    {
        start /= 10;
    }
    if (digit_counter (number) == 15 && (start / 10 == 3 && ( start % 10 == 4 || start % 10 == 7)))
    {
        printf ("AMEX\n");
    }
    else if (digit_counter (number) == 16 && (start / 10 == 5 && (start % 10 >= 1 && start % 10 <= 5)))
    {
        printf ("MASTERCARD\n");
    }
    else if ((digit_counter (number) == 13 || digit_counter (number) == 16) && (start / 10 == 4))
    {
        printf ("VISA\n");
    }
    else
    {
        printf ("INVALID\n");
    }

}

bool checksum (long credit)
{
    int sum = 0;
    while (credit > 0)
    {

        int st = credit % 10;
        sum += st;
        credit /= 10; // first last number
        int nd = credit % 10 * 2;
        if ( nd > 9)
        {
            nd %= 10;
            nd += 1;
        }
        sum += nd;
        credit /= 10; // second last number
    }
    if ( sum % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int digit_counter (long credit)
{
    int sum = 0;
    while (credit > 0)
    {
        credit /= 10;
        sum++;
    }
    return sum;
}


