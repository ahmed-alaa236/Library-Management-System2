#include <iostream>
#include <string>
#include "Book.hpp"
#include "Library.hpp"
#include "BorrowManager.hpp"
using namespace std;

int main() {
    Library       lib;
    BorrowManager bm;
    int choice;

    do {
        cout << "\n=============================" << endl;
        cout << "    LIBRARY MANAGEMENT SYSTEM" << endl;
        cout << "=============================" << endl;
        cout << "1. Add Book"          << endl;
        cout << "2. Remove Book"       << endl;
        cout << "3. Search by Title"   << endl;
        cout << "4. Search by ISBN"    << endl;
        cout << "5. Display All Books" << endl;
        cout << "6. Borrow Book"       << endl;
        cout << "7. Return Book"       << endl;
        cout << "8. Sort Books"        << endl;
        cout << "9. Borrow History"    << endl;
        cout << "0. Exit"              << endl;
        cout << "=============================" << endl;
        cout << "Enter choice: ";
        cin  >> choice;
        cin.ignore();

        if (choice == 1) {
            // Add Book
            string title, author, ISBN;
            int year;
            cout << "Enter title  : "; getline(cin, title);
            cout << "Enter author : "; getline(cin, author);
            cout << "Enter ISBN   : "; getline(cin, ISBN);
            cout << "Enter year   : "; cin >> year; cin.ignore();

            Book* book = new Book(title, author, ISBN, year);
            lib.addBook(book);

        } else if (choice == 2) {
            // Remove Book
            string ISBN;
            cout << "Enter ISBN to remove: "; getline(cin, ISBN);
            lib.removeBook(ISBN);

        } else if (choice == 3) {
            // Search by Title
            string title;
            cout << "Enter title: "; getline(cin, title);
            Book* found = lib.searchByTitle(title);
            if (found) found->printBook();
            else cout << "Book not found." << endl;

        } else if (choice == 4) {
            // Search by ISBN
            string ISBN;
            cout << "Enter ISBN: "; getline(cin, ISBN);
            Book* found = lib.searchByISBN(ISBN);
            if (found) found->printBook();
            else cout << "Book not found." << endl;

        } else if (choice == 5) {
            // Display All
            lib.displayAll();

        } else if (choice == 6) {
            // Borrow Book
            string ISBN, borrower, date;
            cout << "Enter ISBN        : "; getline(cin, ISBN);
            cout << "Enter your name   : "; getline(cin, borrower);
            cout << "Enter today's date: "; getline(cin, date);
            bm.borrowBook(lib, ISBN, borrower, date);

        } else if (choice == 7) {
            // Return Book
            string ISBN, date;
            cout << "Enter ISBN        : "; getline(cin, ISBN);
            cout << "Enter return date : "; getline(cin, date);
            bm.returnBook(lib, ISBN, date);

        } else if (choice == 8) {
            // Sort Books
            lib.sortByTitle();

        } else if (choice == 9) {
            // Borrow History
            bm.displayHistory();

        } else if (choice == 0) {
            cout << "Goodbye!" << endl;

        } else {
            cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 0);

    return 0;
}