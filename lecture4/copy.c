#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef char *string;
void swap(int *a, int *b);
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    int n = 50;
    printf("%i\n", n);
    // using %p to print the addresses of n
    printf("%p\n", &n);
    // ampersand code & *
    // adderesses and dereference
    // %p
    // set pointer to n addresses
    int *p = &n;

    // The value of n
    // it grabs the data from the memory into a integer type (%i)
    printf("%i\n", *p);

    char *s = "Hi!";
    // print the char H
    printf("%c\n", *s);
    printf("%c\n", *(s + 1));
    printf("%c\n", *(s + 2));
    printf("%s\n", s);
    // this will print i!
    printf("%s\n", s + 1);
    printf("%s\n", s + 2);

    printf("%p\n", s);
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);
    printf("%p\n", &s[4]);
    printf("%p\n", &s[5]);

    string d = "Babuga";
    printf("%s\n", d);

    // int i = get_int("i: ");
    // int j = get_int("j: ");

    // // return true if the value of i and j is the same
    // if (i == j || j == i)
    // {
    //     printf("true\n");
    // }
    // else
    // {
    //     printf("false\n");
    // }

    // char *u = get_string("s: ");
    // char *t = get_string("t: ");
    // print string but with different location
    // print the addresses of pointer itself
    // printf("%p\n", &u);
    // printf("%p\n", &t);

    // if (strcmp(u,t) == 0)
    // {
    //     printf("Same\n");
    // }
    // else
    // {
    //     printf("Different\n");
    // }

    // make a copy of string and capitalize it

    // // get user input
    // char *text = get_string("s: ");

    // // this won't  work because it points to the same location in the memory or the same variable
    // // char *copy = text;

    // // allocate memory to store the variable
    // char *copy = malloc(strlen(text) + 1); // +1 for the null terminator

    // if (copy == NULL)
    // {
    //     printf("Memory allocation failed\n");
    //     return 1;
    // }
    // // this will properly copy using library functions
    // // strcpy(copy, text);
    // // copy[0] = toupper(copy[0]);
    // // printf("text: %s\n", text);
    // // printf("copy : %s\n", copy);

    // for (int i = 0, length = strlen(text); i <= length; i++)
    // {
    //     // this will copy the text into the copy variable

    //     copy[i] = text[i];
    //     // we want to make the first letter capital

    // }
    // if (strlen(copy) > 0)
    // {
    //     copy[0] = toupper(text[0]);
    // }

    // printf("%s\n", text);
    // printf("%s\n", copy);


    // free(copy);


    // // testing valgrind

    // // use malloc to allocate memory for the 3 integer
    // // int *x = malloc(3 * sizeof(int));
    // // initialize 3 integer
    // // if (x == NULL)
    // // {
    // //     printf("Memory allocation error\n");
    // //     // return 1 means there is an error
    // //     return 1;
    // // }
    // // x[0] = 75;
    // // x[1] = 89;
    // // x[2] = 80;
    // // print all the three x in one line
    // // printf("%i %i %i\n", x[0],x[1],x[2]);
    // // free(x);

    // // prtinf the swap

    // int a = 5;
    // int b = 7;
    // // pointers x that led to address of a
    // int *x = &a;
    // // pointers of y that led to address of b
    // int *y = &b;
    // // x is a and y is 7
    // swap(x, y);


    // int l;
    // printf("n: ");
    // // put the address of n
    // scanf("%i", &l);
    // printf("n: %i\n", l);

    // char *z = malloc(100 * sizeof(char));

    // printf("z: ");
    // scanf("%99s", z);
    // // assign user input into z using scanf
    // printf("z: %s\n", z);
    // free(z);

    // input output file
    // using append or write
    FILE *file = fopen("phonebook.csv", "a");
    if (file == NULL)
    {
        return 1;
    }

    char *name = get_string("Name: ");
    char *number  = get_string("Number: ");

    fprintf(file, "%s,%s\n", name, number);

    fclose(file);

    //using copy
    FILE *src = fopen(argv[1], "r");
    FILE *dst = fopen(argv[2], "w");

    BYTE b;

    // iterate through all the byte 1 by 1, form source to destination
    while(fread(&b, sizeof(b), 1, src) != 0)
    {
        fwrite(&b, sizeof(b), 1, dst);
    }

    fclose(dst);
    fclose(src);

    if (argc < 2)
    {
        printf("Usage: ./program_name argument\n");
        return 1;
    }


    //pointers that lead into another pointers
    int number1 = 5;
    // stores address of number1
    int *pointer1 = &number1;
    int **pointer2 = &pointer1;
    int ***pointer3 = &pointer2;

    //print the value
    printf("pointer 1 is %p\n", pointer1);
    printf("pointer 2 is %p\n", pointer2);
    printf("pointer 3 is %p\n", pointer3);
    printf("testing\n");
    return 0;
}

void swap(int *a, int *b)
{
    // using pointers and reference
    //swap both variable
    int temporary = *a;
    *a = *b;
    *b = temporary;
    printf("a is: %i, b is : %i\n", *a, *b);
}
