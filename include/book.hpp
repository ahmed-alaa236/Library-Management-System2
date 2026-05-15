#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string ISBN;
    int    year;
    bool   available;

public:
    // Constructor & Destructor
    Book(string title, string author, string ISBN, int year);
    ~Book();

    // Getters
    string getTitle()  const;
    string getAuthor() const;
    string getISBN()   const;
    int    getYear()   const;
    bool   isAvailable() const;

    // Setter
    void setAvailability(bool status);

    // Display
    void printBook() const;
};

#endif