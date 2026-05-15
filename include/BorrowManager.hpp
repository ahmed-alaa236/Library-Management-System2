#ifndef BORROWMANAGER_HPP
#define BORROWMANAGER_HPP

#include "Book.hpp"
#include "Library.hpp"

// Borrow record stored in the Queue
struct BorrowRecord {
    string ISBN;
    string borrowerName;
    string borrowDate;
    string returnDate;
    BorrowRecord* next;

    BorrowRecord(string isbn, string name, string date)
        : ISBN(isbn), borrowerName(name), borrowDate(date),
          returnDate("Not returned"), next(nullptr) {}
};

class BorrowManager {
private:
    BorrowRecord* front;  // front of queue
    BorrowRecord* rear;   // rear of queue
    int           count;

public:
    // Constructor & Destructor
    BorrowManager();
    ~BorrowManager();

    // Core operations
    bool borrowBook(Library& lib, const string& ISBN, const string& borrower, const string& date);
    bool returnBook(Library& lib, const string& ISBN, const string& returnDate);

    // Query
    bool isBookBorrowed(const string& ISBN) const;

    // Display
    void displayHistory() const;
};

#endif