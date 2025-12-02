#include "../include/index.h"
#include <ctype.h>

// Load documents from Cranfield dataset
int loadDocuments(const char* filename, Document* docs) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Error opening Cranfield dataset");
        return 0;
    }

    int id = 0;
    char line[1024];

    while (fgets(line, sizeof(line), file)) {
        // Each document starts with ".I <id>"
        if (strncmp(line, ".I", 2) == 0) {
            id++;
            docs[id - 1].id = id;
            docs[id - 1].title[0] = '\0';
        }
        // Title section starts after ".T"
        else if (strncmp(line, ".T", 2) == 0) {
            char title[512] = "";
            while (fgets(line, sizeof(line), file) && strncmp(line, ".", 1) != 0) {
                strcat(title, line);
            }
            // Store title safely
            strncpy(docs[id - 1].title, title, sizeof(docs[id - 1].title) - 1);
            docs[id - 1].title[sizeof(docs[id - 1].title) - 1] = '\0';
        }
    }

    fclose(file);
    return id;
}

// Build index (insert words from each document)
void buildIndex(TrieNode* root, Document* docs, int docCount) {
    char word[64];

    for (int i = 0; i < docCount; i++) {
        char* text = docs[i].title;
        int j = 0;

        for (int k = 0; ; k++) {
            char c = tolower(text[k]);

            if (isalpha(c)) {
                word[j++] = c;
            } else {
                if (j > 0) {
                    word[j] = '\0';
                    insertWord(root, word, docs[i].id);  // uses function from trie.c
                    j = 0;
                }
                if (text[k] == '\0')
                    break;
            }
        }
    }
}
