#include <cs50.h>
#include <stdio.h>
#include <string.h>

int string_length(string s);
int main(void)
{
    string words[2];
    words[0] = "HI!";
    words[1] = "BYE!";

    // string is basically an array and you can access it
    // this particular string s using indexing
    // printf("%c%c%c\n", words[0][0], words[0][1],words[0][2]);
    // printf("%c%c%c%c\n", words[1][0], words[1][1], words[1][2], words[1][3]);

    string name = get_string("Input your name: \n");
    // int length = string_length(name);
    int name_length = strlen(name);
    printf("Length of the string is %i\n", name_length);


}

int string_length(string s)
{
    int n = 0;
    while (s[n] != '\0')
    {
        n++;
    }
    return n;

}
