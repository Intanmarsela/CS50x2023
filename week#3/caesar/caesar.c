#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, string argv[])
{
 if (argc != 2)
 {
    printf ("Usage: ./caesar key\n");
    return 1;
 }
 string key = argv[1];
int check = atoi(argv[1]);
for (int i = 0; i < strlen(key); i++)
    {
        if (!isdigit(key[i]))
        {
            printf("Key must be a positive integer.\n");
            return 1;
        }
    }
string text = get_string ("Plaintext: ");
printf ("ciphertext: ");
for (int i = 0, n = strlen(text); i < n; i++)
    {
      if (text[i] >= 'a' && text[i] <= 'z')
      {
        printf ("%c", (((text[i])- 'a' + check ) % 26) + 'a');
        }
      else if (text[i] >= 'A'&& text[i] <='Z')
      {
        printf ("%c", (((text[i])- 'A' + check) % 26) + 'A');
        }
      else
      {
        printf ("%c", text[i]);
        }
    }
    printf ("\n");

 return 0;
}
