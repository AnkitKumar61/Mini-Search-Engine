#ifndef SEARCH_H
#define SEARCH_H

#include "index.h"

typedef struct {
    char title[256];
} SearchResult;

void searchQuery(TrieNode* root, Document* docs, int docCount, const char* query);
int getSearchResults(TrieNode* root, Document* docs, int docCount,
                     const char* query, SearchResult* results);

#endif
