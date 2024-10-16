// Prepends numbers to a linked list, using while loop to print

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(int argc, char *argv[])
{
    // Memory for numbers
    node *list = NULL;

    // For each command-line argument
    for (int i = 1; i < argc; i++)
    {
        // Convert argument to int
        int number = atoi(argv[i]);

        // Allocate node for number
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        // put in the number from the argument
        // this is basically the first one(parents node)
        n->number = number;
        n->next = NULL;

        // Prepend node to list
        n->next = list;
        list = n;
    }

    // Print numbers
    // pointer to list which is the node itself
    node *ptr = list;
    while (ptr != NULL)
    {
        printf("%i\n", ptr->number);
        ptr = ptr->next;
    }

    // Free memory
    // why is ptr = list? list is the node itself
    ptr = list;
    // while pointer does not equal null , assign the value of ptr->next to *next and free the pointer , and move ptr to the next one
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
        // this will basically clear the memory one by one using while loop
    }
}
