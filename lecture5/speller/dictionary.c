// Implements a dictionary's functionality
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h> // for reading the files
#include <stdlib.h>
#include <strings.h>
#include <cs50.h>
#include <string.h>
// the file from dictionary.h
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    // length is 45
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 10000;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    char lowercase_word[LENGTH + 1];
    for (int i = 0; word[i] != '\0'; i++)
    {
        lowercase_word[i] = tolower(word[i]);
    }
    lowercase_word[strlen(word)] = '\0';
    unsigned int hash_value = hash(lowercase_word);
    // if word is in dictionary return true else false
    for (node *n = table[hash_value]; n != NULL; n = n->next)
    {
        // return true if each word is in dictionary
        char lowercase_node_word[LENGTH + 1];
        for (int i = 0; n->word[i] != '\0'; i++)
        {
            lowercase_node_word[i] = tolower(n->word[i]);
        }
        lowercase_node_word[strlen(n->word)] = '\0';
        if (strcasecmp(lowercase_word, lowercase_node_word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int hash_value = 0;
    // input word, with alphabetical characters and possibliy aposthropes
    for (int i = 0; word[i] != '\0'; i++)
    {
        hash_value = (hash_value * 33 + word[i]) % N;
    }
    return hash_value;
    // output: numerical index between 0 and N -1, inclusive
    // deterministic
    return toupper(word[0]) - 'A'; // this will return positive integer value
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Open dictionary files
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        printf("Cannot open file\n");
        return false;
    }
    // read strings from file one at a time, using loops
    char word[LENGTH + 1];
    while (fscanf(dict, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Memory allocation error\n");
            fclose(dict);
            return false;
        }

        for (int i = 0; word[i] != '\0'; i++)
        {
            word[i] = tolower(word[i]);
        }
        // create new node for each word, using strcpy and malloc
        strcpy(n->word, word);
        // hash word to obtain a hash value, using the hash function
        // insert node into hash table at that location
        n->next = table[hash(word)];
        table[hash(word)] = n;
    }
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    // count each word as you load it into the dictionary. return that count when size it called
    int count = 0;
    // each time size is called, iterate through the word in the hash table to count them up. Return
    // that count
    for (int i = 0; i < N; i++)
    {
        for (node *n = table[i]; n != NULL; n = n->next)
        {
            count++;
        }
    }
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    // free any memory that you allocatedin load
    for (int i = 0; i < N; i++)
    {
        node *n = table[i];
        // this means n has a value
        while (n != NULL)
        {
            node *temp = n;
            n = n->next;
            free(temp);
        }
    }
    return true;
}
