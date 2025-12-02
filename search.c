#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/search.h"

// Print search results directly (CLI)
void searchQuery(TrieNode* root, Document* docs, int docCount, const char* query) {
    TrieNode* current = root;
    char word[100];
    strcpy(word, query);

    for (int i = 0; word[i]; i++) {
        if (!isalpha(word[i])) continue;
        int index = tolower(word[i]) - 'a';
        if (!current->children[index]) {
            printf("No results found for '%s'\n", query);
            return;
        }
        current = current->children[index];
    }

    if (current->isEndOfWord) {
        printf("\nResults for '%s':\n", query);
        for (int i = 0; i < current->docCount; i++) {
            int id = current->docList[i];
            char cleanTitle[220];
            strncpy(cleanTitle, docs[id - 1].title, sizeof(cleanTitle) - 1);
            cleanTitle[sizeof(cleanTitle) - 1] = '\0';

            for (int j = 0; cleanTitle[j]; j++) {
                if (cleanTitle[j] == '\n' || cleanTitle[j] == '\r' || cleanTitle[j] == '\t')
                    cleanTitle[j] = ' ';
            }

            printf("Doc #%d: %.200s\n", docs[id - 1].id, cleanTitle);
        }
    } else {
        printf("No results found for '%s'\n", query);
    }
}

// Return search results (used internally if needed)
int getSearchResults(TrieNode* root, Document* docs, int docCount,
                     const char* query, SearchResult* results) {
    TrieNode* current = root;
    char word[100];
    strcpy(word, query);
    int totalResults = 0;
    int seenDocs[1500] = {0};

    for (int i = 0; word[i]; i++) {
        if (!isalpha(word[i])) continue;
        int index = tolower(word[i]) - 'a';
        if (!current->children[index]) {
            return 0;
        }
        current = current->children[index];
    }

    if (current->isEndOfWord) {
        for (int i = 0; i < current->docCount; i++) {
            int id = current->docList[i];
            if (seenDocs[id]) continue;
            seenDocs[id] = 1;

            char cleanTitle[220];
            strncpy(cleanTitle, docs[id - 1].title, sizeof(cleanTitle) - 1);
            cleanTitle[sizeof(cleanTitle) - 1] = '\0';
            for (int j = 0; cleanTitle[j]; j++) {
                if (cleanTitle[j] == '\n' || cleanTitle[j] == '\r' || cleanTitle[j] == '\t')
                    cleanTitle[j] = ' ';
            }

            snprintf(results[totalResults].title,
                     sizeof(results[totalResults].title),
                     "Doc #%d: %.200s",
                     docs[id - 1].id, cleanTitle);

            totalResults++;
            if (totalResults >= 100) break;
        }
    }

    return totalResults;
}
