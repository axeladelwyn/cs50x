#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char rotate(char c, int n);
bool only_digits(string s);

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);
    string input = get_string("plaintext: ");
    printf("ciphertext: ");
    // what should i do?
    // shift each character to the left/ right
    // loop through string
    // shift that string into somthing else
    // each (character + key) % 26 = cipher text
    // is upper
    // is lower
    for (int i = 0, length = strlen(input); i < length; i++)
    {
        printf("%c", rotate(input[i], key));
    }
    printf("\n");

    // output will be string (character + key) % 26 = string chipertext
    // string output = shift_letter(input);
}

char rotate(char c, int n)
{
    if (isupper(c))
    {
        // rotate the character
        // n is the key
        return (c - 'A' + n) % 26 + 'A';
    }
    else if (islower(c))
    {
        return (c - 'a' + n) % 26 + 'a';
    }
    else
    {
        return c;
    }
}

bool only_digits(string s)
{

    for (int i = 0, length = strlen(s); i < length; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
    // return false if its not digit
}
