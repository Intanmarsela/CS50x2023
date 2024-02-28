//print our two pyramids facing each other using loop.

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = 0;
    while (height < 1 || height > 8)
    {
        height = get_int ("Heigh: ");
    }
    for (int i = 0; i < height; i++)
    {
        for(int d = height -1; d > i; d--)
        {
            printf (" ");
        }
        printf ("#");

        for(int j = 0 ; j < i; j++)
        {
            printf ("#");
        }
        printf ("  ");
        printf ("#");
        for(int j = 0 ; j < i; j++)
        {
            printf ("#");
        }
        printf ("\n");
    }

}
