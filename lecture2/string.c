#include <cs50.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
    string s = get_string("Input: ");
    // int length = strlen(s);
    printf("Output: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c", s[i]);
    }
    printf("\n");
}
