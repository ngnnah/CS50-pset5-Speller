// Implements a dictionary's functionality

#include <stdbool.h>
#include "dictionary.h"
#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <ctype.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 1024*512;
const unsigned int PRIME = 97;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // check will only be passed words that contain (uppercase or lowercase) alphabetical characters and possibly apostrophes.
    // To compare two strings case-insensitively, you may find strcasecmp (declared in strings.h) useful! 
    // You’ll likely also want to ensure that your hash function is case-insensitive, such that foo and FOO have the same hash value.
    
    // turn the input word into all lower cases
    char lower[LENGTH+1];
    int c = 0;
    while (word[c] != '\0')
    {
        lower[c] = tolower(word[c]);
        c++;
    }
    lower[c] = '\0';

    // get the head at index = hash(lower)
    node *n = table[hash(lower)];
    while (n != NULL)
    {
        if (strcmp(n->word, lower) == 0)
        {
            return true;
        }
        else
        {
            n = n->next;
        }
    }
    // not found in dictionary
    return false;
}

// Hashes word to a number
// words: lower case letters, and apostrophes '
unsigned int hash(const char *word)
{
    int c = 0;
    unsigned int h = 0;
    while(word[c] != '\0') {
        h = h * PRIME + word[c];
        c++;
    } 
    return h % N;
}

int word_count = 0;
// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO alphabetically sorted from top to bottom with one word per line, each of which ends with \n.
    // contain at least one word, that no word will be longer than LENGTH
    // that no word will appear more than once, that each word will contain only lowercase alphabetical characters 
    // and possibly apostrophes, and that no word will start with an apostrophe.
   // printf("STARTING dictionary load \n");
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return false;
    }
    
    char word[LENGTH+1];
    // read word by word, i.e. line by line
    while (fscanf(file, "%s", word) != EOF)
    {
        word_count++;
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Memory allocation error, using malloc. \n");
            return false;
        }
        strcpy(n->word, word);
        // hashing the word and store into table
        unsigned int h = hash(word);
        if (table[h] == NULL)
        {
            // first node, so we make new head
            table[h] = n;
            n->next = NULL;
        }
        else
        {
            node *head = table[h];
            n->next = head->next;
            head->next = n;
        }
    }
    fclose(file); // dont forget to close dictionary file
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // // Your spell checker must not leak any memory. Be sure to check for leaks with valgrind.
    for (int i = 0; i < N ; i++) 
    {
        // for each bucket, free each node
        node *n = table[i];
        while (n != NULL)
        {
            node *tmp = n;
            n = n->next;
            free(tmp);
        }
    }
    return true;
}


