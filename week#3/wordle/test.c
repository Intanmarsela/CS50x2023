#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>



int main(void)
{
    string guess = ("Blackpink");
    int wordsize = 9;
    string choice = ("knipkcalB");
    for (int i = 0; i < wordsize; i++)
    {
        if(guess[i] == choice [i]) // right word in the right position.
        {
            printf("2\n");
        }
        else
        {
            int match = 0;
          for (int j = 0; j < wordsize; j++)
             {
               if(choice[i] == guess[j])
               {    printf("1\n");
                    match = 1;
                    break;
               }
             }
             if (!match)
             {
                printf ("0\n");
             }
        }
    }
}