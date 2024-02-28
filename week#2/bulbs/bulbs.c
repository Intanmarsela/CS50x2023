#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;
char to_binary (int input);

void print_bulb(int bit);

int main(void)
{
    string message = get_string("Message: "); // for the input// TODO
    int length = strlen(message); // the length of the input
    char input[length]; //to store the input
    int ascii[length]; //to store the int of the input
    for(int i = 0; i < length; i++) // going throught every single char
    {
        input[i] = message[i]; //passing message to char input (single char)
        ascii[i] = input[i]; // passing the char into int ascii
 //to check if the ascii is storing the ascii of the char
    }
    int binary[7]; //to store the binary of a single char
    for(int i = 0; i < length; i++) // going through the length
    {
        for(int j = 7; j > -1; j--) // making the single char inside the length into binary
        {
            binary[j] = ascii[i] % 2;
            ascii[i] /=2;
        }
        for (int p = 0; p < 8; p++)
        {
            print_bulb(binary[p]);
        }
        printf("\n");
    }
}


void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
