#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node
{
    string phrase;
    struct node *next;
} node;

node *table[26];
// function to determine the bucket for given phrase
int hash(string phrase);
// functino to free memory uesd by the linked list
bool unload(node *list);
// function to visualize the linked list
void visualizer(node *list);

// main functions
int main(void)
{
    // Add items
    // run three times to get three phrases from the user
    for (int i = 0; i < 3; i++)
    {
        // prompt the user the enter a phrase
        string phrase = get_string("Enter a new phrase: ");

        // Find phrase bucket
        // call the hash functions to determinet he bucket for the phrase
        int bucket = hash(phrase);
        printf("%s hashes to %i\n", phrase, bucket);
    }
}

// TODO: return the correct bucket for a given phrase
int hash(string phrase)
{
    // convert first character of the phrase to determine the bucket
    char first_char = tolower(phrase[0]); // convert to lowercase
    // Map the character to a bucket
    int bucket = first_char - 'a';
    return bucket;
}
