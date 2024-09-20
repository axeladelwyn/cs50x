#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // get input prompt from user
    string name = get_string("Input your name: ");
    // print the name
    printf("Hello, %s\n", name);
}
