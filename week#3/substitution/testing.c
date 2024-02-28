#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

int main (void)
{
string plain = get_string ("plaintext: ");
printf ("ciphertext: ");
for (int i = 0; i < strlen(plain); i++)
{
    printf ("%c", plain [i]);
    printf ("\n");
}
}