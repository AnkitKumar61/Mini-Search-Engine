#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/index.h"
#include "../include/search.h"

void showMenu() {
    printf("\n==== CranSearcher ====\n");
    printf("1. Build Index\n");
    printf("2. Search Query\n");
    printf("3. Exit\n");
    printf("======================\n");
}

int main() {
    TrieNode* root = createTrieNode();
    Document docs[1500];
    int docCount = 0;

    int choice;
    char query[200];

    while (1) {
        showMenu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            printf("\nBuilding index...\n");
            docCount = loadDocuments("data/cran.all.1400", docs);
            if (docCount == 0) {
                printf("Error: Failed to load documents.\n");
                continue;
            }
            buildIndex(root, docs, docCount);
            printf("✅ Index built for %d documents.\n", docCount);
        } 
        else if (choice == 2) {
            if (docCount == 0) {
                printf("⚠️ Please build the index first (option 1).\n");
                continue;
            }
            printf("Enter search query: ");
            fgets(query, sizeof(query), stdin);
            query[strcspn(query, "\n")] = '\0';
            searchQuery(root, docs, docCount, query);
        } 
        else if (choice == 3) {
            printf("Exiting CranSearcher...\n");
            break;
        } 
        else {
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
