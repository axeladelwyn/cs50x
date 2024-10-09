<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // make sure the argument it at certain number
=======
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int const bytes_blocks = 512;
int main(int argc, char *argv[])
{
    // make sure the argument it at certain number otherwise you return error
    // make pseudo code
    // how do i recover file? loop through the deleted bytes and
    if (argc != 2) // two because 1 is for the file name
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }
    FILE *img = NULL;
    char filename[8];
    FILE *card = fopen(argv[1], "r"); // read the second argument which is the card raw data

    // check if the file open properly
    if (card == NULL)
    {
        printf("Can't open file\n");
        return 1;
    }

    // store the data in the buffer, unit8_t exactly stores 1 bytes ( 8 bit)
    uint8_t buffer[bytes_blocks]; // using 512 bytes
    int count = 0;
    // if file already open
    // then write if its open
    while (fread(buffer, 1, bytes_blocks, card) == 512) // read the card and check if its 512 bytes?
    {
        // using sprintf and naming ###.jpg , where ### is three-digit decimal
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (img != NULL)
            {
                fclose(img);
            }
            sprintf(filename, "%03i.jpg", count);
            img = fopen(filename, "w");
            count++;
        }
        if (img != NULL)
        {
            fwrite(buffer, 1, bytes_blocks, img);
        }
    }
    if (img != NULL)
    {
        fclose(img);
    }

    fclose(card);
    return 0;
    // Open memory card
    // Repeat until end of card:
    // Read 512 bytes into a buffer
    // If start of a new JPEG
    // If first JPEG
    // ...
    // else
    // ...
    // else if already found JPEG
    // File *f = fopen(filename, "r")

    // Look for beginning of a JPEG
    // distinct header for jpeg is 0xff 0xd8 0xf 0xef, JPegs is stored back to back.

    // Open a new JPEG file
    // Write 512 bytes until a new JPEG is found.
    // keep writing files until a new jpeg is found
    // sprintf(filename, %03i.jpg", 2);
    // FILE *img = fopen (filename, "w")
    // fwrite(data, size, number, output);
>>>>>>> 2c9c88b (lecture 5)
}
