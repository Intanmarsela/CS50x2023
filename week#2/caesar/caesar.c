#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    while (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int key = atoi(argv[1]);
    string digit = (argv[1]);
    for(int i = 0; i < strlen(digit); i++)
    {
        if (!isdigit(digit[i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    if (key == 0 || key < 0 )
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    string text = get_string ("Plaintext: ");
    int length = strlen(text);
    int ciper[length];
    printf ("Ciphertext: ");
    for (int i = 0; i < length; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = (((text[i] - 'a' + key ) %26) + 'a');
            printf ("%c", text[i]);
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = (((text[i] - 'A' + key) %26) + 'A');
            printf ("%c", text[i]);
        }
        else
        {
            printf ("%c", text[i]);
        }
    }
    printf ("\n");
    return 0;
}


