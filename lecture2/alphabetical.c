#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string phrase = get_string("Enter a phrase: ");
    int length = strlen(phrase) - 1;
    for (int i = 0; i < length; i++)
    {
        printf("%i \n", phrase[i]);
        // how do i know something is it alphabetical order
        // using the ascii table??
        // check if characters are not alphabetical
        if (phrase[i] > phrase[i + 1])
        {
            printf("Not in all alphabetical order.\n");
            return 0;
        }
    }
    printf("Alphabetical order!\n");
    return 0;
}
