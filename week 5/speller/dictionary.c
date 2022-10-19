// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 100000;

// Hash table
node *table[N];

//counts words loaded from dictionary
int DicCount = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int hWord = hash(word);
    node *tword = table[hWord];
    while(word != NULL & tword != NULL){
        if (strcasecmp(word , tword->word) == 0){
            return true;
        }
       tword = tword -> next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{

    // TODO: Improve this hash function
    // This hash function is djb2. I got this function from http://www.cse.yorku.ca/~oz/hash.html

    unsigned long hash = 5381;
    int c;
    while((c = tolower(*word++))){
        hash = ((hash << 5) + hash) + c;
    }
    int val = (hash % N);
    return val;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *Pdictionary = fopen(dictionary,"r");

    if (Pdictionary == NULL){
        printf("Invalid dictionary");
        return false;
    }
    char nextword[LENGTH + 1];
    while(fscanf(Pdictionary,"%s",nextword) != EOF){
        node *rw = malloc(sizeof(node));
        if(rw == NULL){
            printf("not enough memory");
            return false;
        }
        strcpy(rw -> word,nextword);
        int hashnum = hash(nextword);
        rw -> next = table[hashnum];
        table[hashnum] = rw;
        DicCount++;
    }
    fclose(Pdictionary);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return DicCount;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for(int i = 0; i < N; i++){
        node *n = table[i];
        while (n != NULL){
            node *tmp = n;
            n = n->next;
            free(tmp);
        }
        if(n == NULL && i == N - 1){
            return true;
        }
    }
    return false;
}