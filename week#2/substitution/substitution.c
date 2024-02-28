#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>

bool double_alpha (const string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf ("Usage: ./substitution key \n");
        return 1;
    }
    const string key = argv[1];
    int num_key = strlen(key);
    if (num_key != 26)
    {
        printf ("Key must contain 26 characters\n");
        return 1;
    }
    for (int i = 0; i < num_key; i++)
    {
        if ( !isalpha(key[i]))
        {
            printf ("Usage: ./substitution key\n ");
            return 1;
        }
    }
    if (!double_alpha(key))
    {
        printf ("Key must contain 26 different characters\n");
        return 1;
    }
    string text = get_string ("Plaintext: ");
    printf("ciphertext: ");
    int ltext = strlen(text);
    for (int i = 0; i < ltext; i++)
    {
        int num_text = 0;
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] -= 'a';
            num_text += text[i];
            printf("%c", tolower (key[num_text]));
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] -= 'A';
            num_text += text[i];
            printf("%c", toupper(key[num_text]));
        }
        else
        {
            printf ("%c", text[i]);
        }
    }
    printf ("\n");

}

bool double_alpha (const string key) //make sure it is checking the key so it will not double and ignore the case
{
    char ciperkey[26];
    for (int i = 0 ; i < 26; i++)
    {
        ciperkey[i] = tolower(key[i]);
    }
    for(int j = 0; j < 26; j++)
    {
        int counter = 0;
        for (int i = 0; i < 26; i++)
        {
            if (ciperkey[j] == ciperkey[i])
            {
                counter++;
            }
        }
        if (counter > 1)
        {
            return false;
        }
    }
    return true;
}
