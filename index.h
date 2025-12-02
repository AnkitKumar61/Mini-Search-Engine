#ifndef INDEX_H
#define INDEX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/trie.h"   // 👈 include trie here

#define MAX_DOCS 1500
#define MAX_TITLE_LEN 512

typedef struct {
    int id;
    char title[MAX_TITLE_LEN];
} Document;

// Function prototypes
void buildIndex(TrieNode* root, Document* docs, int docCount);
int loadDocuments(const char* filename, Document* docs);

#endif
