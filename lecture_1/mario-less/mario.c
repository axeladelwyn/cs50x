#include <cs50.h>
#include <stdio.h>

void print_hash(int spaces, int length);

int main(void)
{
    int n;
    do
    {
        n = get_int("Input the size of the pyramid: ");
    }
    while (n <= 0 || n > 8);
    // using for loops

    for (int count = 0; count < n; count++)
    {
        // left aligned pyramid completed
        // now we need to add dot somehow
        // to make right align pyramid
        print_hash(n - count - 1, count + 1);
    }
}

// make functions for printing hash
void print_hash(int spaces, int length)
{
    for (int i = 0; i < spaces; i++)
    {
        printf(" ");
    }
    for (int i = 0; i < length; i++)
    {

        printf("#");
    }
    printf("\n");
}
