// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;
// take 3 argument, take string argv
int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        // if the argument is not equal 4 print this
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        // open the file
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        // output the file
        printf("Could not open file.\n");
        return 1;
    }
    // what is atof? convert to float.
    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    // using FILE * , using loop? multiply by volume factor * sample value and write it to the new
    // output file uint8_t or uint16_t using fread and fwrite and remember 44 bytes
    // this will copy the header into the ouput basically making it wav file?
    uint8_t header[HEADER_SIZE];
    fread(header, HEADER_SIZE, 1, input);
    fwrite(header, HEADER_SIZE, 1, output);
    // TODO: Read samples from input file and write updated data to output file
    int16_t buffer;
    // this gonna keep reading the file until end of line, &buffer is the address of the buffer
    while (fread(&buffer, sizeof(int16_t), 1, input) != 0)
    {
        buffer *= factor;
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }

    // update the volume

    // and write back to the file

    // somehow manipulate the volume
    // fwrite the updated data
    // Close files
    fclose(input);
    fclose(output);
}
