#include "BorrowManager.hpp"
#include <iostream>
using namespace std;

BorrowManager::BorrowManager() : front(nullptr), rear(nullptr), count(0) {}

BorrowManager::~BorrowManager() {
    BorrowRecord* curr = front;
    while (curr != nullptr) {
        BorrowRecord* next = curr->next;
        delete curr;
        curr = next;
    }
}

bool BorrowManager::borrowBook(Library& lib, const string& ISBN,
                                const string& borrower, const string& date) {
    Book* book = lib.searchByISBN(ISBN);

    if (!book) {
        cout << "Book not found." << endl;
        return false;
    }
    if (!book->isAvailable()) {
        cout << "Book is already borrowed." << endl;
        return false;
    }

    book->setAvailability(false);

    BorrowRecord* record = new BorrowRecord(ISBN, borrower, date);
    if (rear == nullptr) {
        front = rear = record;
    } else {
        rear->next = record;
        rear = record;
    }
    count++;

    cout << book->getTitle() << " borrowed by " << borrower << endl;
    return true;
}

bool BorrowManager::returnBook(Library& lib, const string& ISBN,
                                const string& returnDate) {
    Book* book = lib.searchByISBN(ISBN);

    if (!book) {
        cout << "Book not found." << endl;
        return false;
    }
    if (book->isAvailable()) {
        cout << "Book was not borrowed." << endl;
        return false;
    }

    book->setAvailability(true);

    BorrowRecord* curr = front;
    while (curr != nullptr) {
        if (curr->ISBN == ISBN && curr->returnDate == "Not returned") {
            curr->returnDate = returnDate;
            break;
        }
        curr = curr->next;
    }

    cout << book->getTitle() << " returned." << endl;
    return true;
}

bool BorrowManager::isBookBorrowed(const string& ISBN) const {
    BorrowRecord* curr = front;
    while (curr != nullptr) {
        if (curr->ISBN == ISBN && curr->returnDate == "Not returned")
            return true;
        curr = curr->next;
    }
    return false;
}

void BorrowManager::displayHistory() const {
    if (!front) {
        cout << "No borrow history." << endl;
        return;
    }
    BorrowRecord* curr = front;
    int i = 1;
    while (curr != nullptr) {
        cout << "-------------------------------" << endl;
        cout << "Record   : " << i++              << endl;
        cout << "ISBN     : " << curr->ISBN        << endl;
        cout << "Borrower : " << curr->borrowerName << endl;
        cout << "Borrowed : " << curr->borrowDate   << endl;
        cout << "Returned : " << curr->returnDate   << endl;
        curr = curr->next;
    }
    cout << "-------------------------------" << endl;
}