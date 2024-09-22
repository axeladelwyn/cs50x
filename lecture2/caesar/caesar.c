#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    int arg = atoi(*argv);
    if (argc != 2 )
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else if (!isdigit((argv[1][0])))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string input = get_string("plaintext: ");
    // what should i do?
    // shift each character to the left/ right
    // loop through string
    // shift that string into somthing else
    // each (character + key) % 26 = cipher text
    // is upper
    // is lower



    // output will be string (character + key) % 26 = string chipertext
    // string output = shift_letter(input);
}

// make a function that will output the cipher


