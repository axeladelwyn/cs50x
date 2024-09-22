#include <stdio.h>
#include <cs50.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2 )
    {
        printf("Missing/Too much argument\n");
        return 1;
    }
    else if (!isdigit(argv[1][0]))
    {
        printf("Argument is not a digit\n");
        return 1;
    }
    printf("hello, %s\n", argv[1]);
    return 0;
    // what should i do?
    // shift each character to the left/ right
    // loop through string
    // shift that string into somthing else

}

