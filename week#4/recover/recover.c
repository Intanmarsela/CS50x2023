#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE");
        return 1;
    }
    char *input = argv[1];
    FILE *inputed = fopen(input, "r");
    if (inputed == NULL)
    {
        printf ("Error: Can not open the file %s", input);
        return 2;
    }
    BYTE buffer[512];
    int count = 0;
    FILE *img_inputed = NULL;
    char filename[8];

    while (fread(&buffer, 512, 1, inputed) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (count != 0 )
            {
                fclose(img_inputed);
            }
            sprintf(filename, "%03i.jpg", count);
            img_inputed = fopen(filename, "w");
            count++;
        }
        if (count != 0)
        {
            fwrite(&buffer,512,1,img_inputed);
        }
    }
    fclose(inputed);
    fclose (img_inputed);

    return 0;

}
