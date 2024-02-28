//Calculating readability tests with Coleman-Liau index formula.

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    char *input = get_string ("Text: "); //promp the user for the text.

    int c = strlen(input);
    double letters = 0;
    double words = 1;
    double sentences = 0;
    char lower[c];
    for (int i = 0; i < c; i++) //iterate every char of the inputed text.
    {
        lower[i] = tolower(input[i]);
        if (isalpha(lower[i])) //for counting the letters.
        {
            letters++;
        }
        if (isspace(lower[i]))
        {
            words++;
        }
        if (lower[i] == '!' || lower[i] == '.' || lower[i] == '?')
        {
            sentences++;
        }
    }
    double L = letters/words*100;
    double S = sentences/words*100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    if (index >= 16)
    {
        printf ("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf ("Before Grade 1\n");
    }
    else
    {
        printf ("Grade %i\n", index);
    }
}
