# 🕵️‍♂️ Mini Search Engine

Mini Search Engine is a simple and efficient C-based project that indexes text files and performs fast keyword searches. It demonstrates how search engines internally work using indexing, stop-word removal, and string parsing techniques.

---

## 📌 Overview

This project reads text documents, extracts meaningful keywords, builds an index, and allows users to search for any term quickly. It is designed to help students understand core DSA topics like tries, hashing, file handling, and inverted indexing.

---

## 🧠 Features

- Index multiple text files  
- Case-insensitive search  
- Stop-word removal using `stopwords.txt`  
- Efficient lookup using Trie or Hash Table  
- Clean modular structure (`main.c`, `index.c`, `search.c`, `trie.c`)  
- Easy to compile and execute  

---

## 📁 Project Structure
Mini-Search-Engine/
│
├── main.c # Entry point of the program
├── index.c # Logic for building the index
├── index.h
├── search.c # Search logic for handling queries
├── search.h
├── trie.c # Trie implementation (if used)
├── trie.h
├── stopwords.txt # List of common stop-words
└── README.md # Project documentation 

---

## ⚙️ Installation & Compilation

### 1. Clone the repository
```bash
git clone https://github.com/AnkitKumar61/Mini-Search-Engine
cd Mini-Search-Engine

2. Compile the program
gcc *.c -o mini_search


Or compile manually:

gcc main.c index.c search.c trie.c -o mini_search

3. Run the program
./mini_search

📝 How to Use

Run the compiled program

Enter the file name you want to index (example: data.txt)

The engine will:

Parse the text

Remove stop-words

Build the searchable index

Enter a search keyword

The program prints all occurrences including:

File name

Line number(s)

Example

Input

Enter file name: data.txt
Enter search word: computer


Output

Found in data.txt at line 2

🧪 Example File (data.txt)
Artificial Intelligence is the future.
Computer science and machine learning are evolving.
Search engines index the internet.

🛠 Internal Working
🔹 1. Tokenization

Splits text into words, removes punctuation, and converts to lowercase.

🔹 2. Stop-word Filtering

Ignores common words using the stopwords.txt list (like "the", "is", "and", etc.).

🔹 3. Index Building

Each valid keyword is stored with:

Its file name

Its line number

Occurrence count

Using either:

Trie (character-by-character storage)

Hash Table

🔹 4. Searching

Matches the exact keyword and prints all locations where it appears.
