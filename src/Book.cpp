#include "Book.hpp"
#include <iostream>
using namespace std;

Book::Book(string t, string a, string isbn, int y)
    : title(t), author(a), ISBN(isbn), year(y), available(true) {}

Book::~Book() {}

string Book::getTitle()    const { return title;  }
string Book::getAuthor()   const { return author; }
string Book::getISBN()     const { return ISBN;   }
int    Book::getYear()     const { return year;   }
bool   Book::isAvailable() const { return available; }

void Book::setAvailability(bool status) {
    available = status;
}





void Book::printBook() const {

    cout << "-------------------------------" << endl;
    
    cout << "Title  : " << title  << endl;
    cout << "Author : " << author << endl;
    cout << "ISBN   : " << ISBN   << endl;
    cout << "Year   : " << year   << endl;
    cout << "Status : " << (available ? "Available" : "Borrowed") << endl;
    cout << "-------------------------------" << endl;
}