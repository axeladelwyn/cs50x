#include <cs50.h>
#include <stdint.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    // Read first four bytes in given file
    char *filename = argv[1];
    FILE *f = fopen(filename, "r");
    if (f == NULL)
    {
        perror("Error opening file.");
        return 1;
    }
    uint8_t buffer[4];
    size_t bytesread = fread(buffer, 1, 4, f);
    // 4 because the buffer has 4 element in it
    if (bytesread < 4)
    {
        //print error
        printf("File is too small!");
        return 2;
    }

    // Print first four bytes in given file
    for (int i = 0; i < 4; i++)
    {
        // usually pdf have a sequence of
        // 37, 80, 68, 70
        printf("%i\n", buffer[i]);
    }
    fclose(f);
    return 0;
}
