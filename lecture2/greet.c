#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    // printf("hello, %s\n", argv[1]);
    // if (argc == 2)
    // {
    //     printf("hello, %s\n", argv[1]);
    // }
    // else
    // {
    //     printf("hello, world\n");
    // }

    for (int i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }
}
