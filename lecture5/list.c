#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// node data structure
typedef struct node
{
    string phrase;
    struct node *next;
} node;

#define LIST_SIZE 2

// pointer to list?
bool unload(node *list);
void visualizer(node *list);

int main(void)
{
    // pointer to list is NULL at beginning
    node *list = NULL;

    // Add items to list
    for (int i = 0; i < LIST_SIZE; i++)
    {
        // Insert phrase to list
        string phrase = get_string("Enter a new phrase: ");

        // TODO: add phrase to new node in list
        node *n = malloc(sizeof(node));

        if (n == NULL)
        {
            printf("Memory allocation error");
            return 1;
        }
        // put phrase into the node
        n->phrase = phrase;
        n->next = NULL;
        // point next into list that is n
        n->next = list;
        list = n;
        // Visualize list after adding a node.
        visualizer(list);
    }

    // Free all memory used
    if (!unload(list))
    {
        printf("Error freeing the list.\n");
        return 1;
    }

    printf("Freed the list.\n");
    return 0;
}
// this function unload the list
bool unload(node *list)
{
    // TODO: Free all allocated nodes
    node *ptr = list;
    // if the code is not NULL then continue
    while(ptr != NULL)
    {
        node *temp = ptr;

        ptr = ptr->next;

        free(temp);
    }
    return true;
}
// this functions visualize the list
void visualizer(node *list)
{
    printf("\n+-- List Visualizer --+\n\n");
    while (list != NULL)
    {
        printf("Location %p\nPhrase: \"%s\"\nNext: %p\n\n", list, list->phrase, list->next);
        list = list->next;
    }
    printf("+---------------------+\n\n");
}
