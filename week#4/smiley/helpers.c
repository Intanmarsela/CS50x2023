#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < width; row++)// Change all black pixels to a color of your choosing
    {
        for (int colomn = 0; colomn < height; colomn++)
        {
            if(image[colomn][row].rgbtRed == 0 && image[row][colomn].rgbtGreen == 0 && image[row][colomn].rgbtBlue == 0)
            {
                image[colomn][row].rgbtGreen = 83;
                image[colomn][row].rgbtRed = 239;
                image[colomn][row].rgbtBlue = 80;
            }
        }
    }

}
