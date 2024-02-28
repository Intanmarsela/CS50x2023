#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

bool alph (const string key_input );

int main(int argc, string argv[])
{
if (argc != 2) // if the key is not inputed
{
    printf ("Usage: ./substitution key\n");
    return 1;
}
const string key = argv[1];
int length = strlen (key);
if (length != 26)
{
    printf ("Key must contain 26 characters\n");
    return 1;
}
for (int i = 0; i < strlen(key); i++) // to check all the key that inputed are alphabetic
{
    if (!isalpha(key[i]))
    {
        printf ("Key must only contain alphabetic characters.\n");
        return 1;
    }
}
if (alph (key))
{
    printf ("Key must not contain repeated characters.\n");
    return 1;
}
string plain = get_string ("plaintext: ");
printf ("ciphertext: ");
for (int i = 0; i < strlen(plain); i++)
{
    int text = plain[i];
    if (text >= 'A' && text <= 'Z')
    {
        int k = text - 'A';
        char g = toupper (key[k]);
        printf ("%c",g);
    }
    else if (text >= 'a' && text <= 'z')
    {
        int l = text - 'a';
        char n = tolower(key[l]);
        printf ("%c",n);
    }
    else 
    {
        printf ("%c", plain[i]);
    }
}
printf ("\n");
}

bool alph (const string key_input)
{
    int counter [26] = {0};
    for (int i = 0; key_input[i] != '\0'; i++)
    {
        char ch = tolower (key_input[i]);

        if (isalpha(ch))
        {
            int index = ch - 'a';
            counter[index]++;
            if (counter[index] > 1)
            {
                return true;
            }
        }
    }
    return false;
}

