// Implements a list of numbers using a linked list
// this is the opposite because the first one is still 1
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
    // assign memory to *list
    // pointer to the first node in the linked list, set to NULL to indicate that the list is empty
    node *list = NULL;


    // For each command-line argument
    for (int i = 1; i < argc; i++)
    {
        // Convert argument that the user give  to integer
        int number = atoi(argv[i]);

        // Allocate node for number, user malloc to the size of node
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        // insert the argument from the user into the linked list
        n->number = number;
        // set the next liked list into NULL
        n->next = NULL;

        // If list is empty
        if (list == NULL)
        {
            // This node is the whole list
            list = n;
        }

        // If list has numbers already
        else
        {
            // Iterate over nodes in list, if ptr does not equal null go into the next linked list
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                // If at end of list
                // this basically only append node at the end of the list?
                if (ptr->next == NULL)
                {
                    // Append node
                    ptr->next = n;
                    break;
                }
            }
        }
    }

    // Print numbers
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }

    // Free memory
    node *ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
}
