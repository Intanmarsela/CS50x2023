#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    if (argc != 3)  // Ensure proper usage
    {
        printf ("Usage: ./reverse <input file> <output file>\n");// TODO #1
        return 1;
    }
    FILE *input = fopen(argv[1], "r");    // Open input file for reading
    if (input == NULL)// TODO #2
    {
        printf ("Could not open file");
        return 2;
    }
    WAVHEADER rheader;// Read header
    fread (&rheader, sizeof(WAVHEADER), 1, input);// TODO #3

    if (check_format(rheader) != 0)// Use check_format to ensure WAV format
    {
        fclose(input);// TODO #4
        return 3;
    }

    FILE *output = fopen(argv[2], "w");// Open output file for writing
    if (output == NULL)// TODO #5
    {
        printf ("Error opening output file\n");
        fclose(output);
        fclose(input);
        return 4;
    }

    fwrite (&rheader, sizeof(WAVHEADER), 1, output);// Write header to file
    // TODO #6

    int size = get_block_size(rheader); // Use get_block_size to calculate size of block
    // TODO #7

    BYTE buffer[size];// Write reversed audio to file
    for (fseek(input, 0 - size, SEEK_END); ftell(input) > sizeof(rheader)-size; fseek(input, 0 - (size * 2), SEEK_CUR))
    {
        fread (&buffer, size, 1, input);// TODO #8
        fwrite (&buffer, size, 1, output);
    }

    fclose(input);
    fclose(output);
    return 0;
}

int check_format(WAVHEADER header)
{
    int wav[] = {0x57, 0x41, 0x56, 0x45};// TODO #4
    for (int i = 0; i < 4; i++)
    {
        if (header.format[i] != wav[i])
        {
            printf ("Invalid WAV file\n");
            return 1;
        }
    }
    return 0;
}

int get_block_size(WAVHEADER header)
{
    int n = header.numChannels * (header.bitsPerSample / 8);// TODO #7
    return n;
}
