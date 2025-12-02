#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../include/trie.h"

// Create a new Trie node
TrieNode* createTrieNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->isEndOfWord = false;
    node->docCount = 0;
    node->docList = NULL;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;
    return node;
}

// Helper to check alphabetic chars
bool isAlpha(char c) {
    return (isalpha((unsigned char)c) != 0);
}

// Insert a word into the trie
void insertWord(TrieNode* root, const char* word, int docID) {
    TrieNode* current = root;

    for (int i = 0; word[i]; i++) {
        if (!isAlpha(word[i])) continue;
        int index = tolower(word[i]) - 'a';
        if (index < 0 || index >= ALPHABET_SIZE) continue;

        if (current->children[index] == NULL)
            current->children[index] = createTrieNode();
        current = current->children[index];
    }

    current->isEndOfWord = true;
    current->docList = realloc(current->docList, (current->docCount + 1) * sizeof(int));
    current->docList[current->docCount++] = docID;
}
