#ifndef TRIE_H
#define TRIE_H

#include <stdbool.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    int* docList;   // array of document IDs
    int docCount;
    bool isEndOfWord;
} TrieNode;

TrieNode* createTrieNode();
void insertWord(TrieNode* root, const char* word, int docID);
bool isAlpha(char c);

#endif
