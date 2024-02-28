#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start;
    do
    {
        start = get_int ("Start population: ");
    }
    while (start < 9);

    int finish;
    do
    {
        finish = get_int ("finishing population: ");
    }
    while (finish < start);
   int years = 0;
    while (start < finish)
    {
        start = start + (start / 3) - (start / 4);
        years++;
    }
    printf ("Years: %i", years);

}

