#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include "Book.hpp"

// Node for the Linked List
struct Node {
    Book*  book;
    Node*  next;
    Node(Book* b) : book(b), next(nullptr) {}
};

class Library {
private:
    Node* head;
    int   size;

public:
    // Constructor & Destructor
    Library();
    ~Library();

    // Core operations
    void addBook(Book* book);
    bool removeBook(const string& ISBN);

    // Search
    Book* searchByTitle(const string& title) const;
    Book* searchByISBN(const string& ISBN)   const;

    // Sort (bubble sort by title)
    void sortByTitle();

    // Display
    void displayAll() const;

    // Getter
    int getSize() const;
};

#endif