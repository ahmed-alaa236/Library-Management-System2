#include "Library.hpp"
#include <iostream>
using namespace std;

Library::Library() : head(nullptr), size(0) {}

Library::~Library() {
    Node* curr = head;
    while (curr != nullptr) {
        Node* next = curr->next;
        delete curr->book;
        delete curr;
        curr = next;
    }
}

void Library::addBook(Book* book) {
    Node* newNode = new Node(book);
    newNode->next = head;
    head = newNode;
    size++;
    cout << "Book added: " << book->getTitle() << endl;
}

bool Library::removeBook(const string& ISBN) {
    Node* curr = head;
    Node* prev = nullptr;

    while (curr != nullptr) {
        if (curr->book->getISBN() == ISBN) {
            if (prev == nullptr)
                head = curr->next;
            else
                prev->next = curr->next;

            cout << "Book removed: " << curr->book->getTitle() << endl;
            delete curr->book;
            delete curr;
            size--;
            return true;
        }
        prev = curr;
        curr = curr->next;
    }

    cout << "Book not found." << endl;
    return false;
}

Book* Library::searchByTitle(const string& title) const {
    Node* curr = head;
    while (curr != nullptr) {
        if (curr->book->getTitle() == title)
            return curr->book;
        curr = curr->next;
    }
    return nullptr;
}

Book* Library::searchByISBN(const string& ISBN) const {
    Node* curr = head;
    while (curr != nullptr) {
        if (curr->book->getISBN() == ISBN)
            return curr->book;
        curr = curr->next;
    }
    return nullptr;
}

void Library::sortByTitle() {
    if (!head || !head->next) return;

    bool swapped;
    do {
        swapped = false;
        Node* curr = head;
        while (curr->next != nullptr) {
            if (curr->book->getTitle() > curr->next->book->getTitle()) {
                Book* temp       = curr->book;
                curr->book       = curr->next->book;
                curr->next->book = temp;
                swapped = true;
            }
            curr = curr->next;
        }
    } while (swapped);

    cout << "Books sorted." << endl;
}

void Library::displayAll() const {
    if (!head) {
        cout << "Library is empty." << endl;
        return;
    }
    Node* curr = head;
    int i = 1;
    while (curr != nullptr) {
        cout << "[" << i++ << "] ";
        curr->book->printBook();
        curr = curr->next;
    }
}

int Library::getSize() const { return size; }