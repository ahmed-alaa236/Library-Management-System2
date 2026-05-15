#include <iostream>
#include "Library.hpp"
#include "BorrowManager.hpp"
using namespace std;

int main() {
    Library lib;
    BorrowManager bm;

    cout << "===== TESTING =====" << endl;

    // Test 1: Normal case - add and borrow a book
    cout << "\n[1] Normal Case:" << endl;
    lib.addBook(new Book("Clean Code", "Robert Martin", "ISBN1", 2008));
    bm.borrowBook(lib, "ISBN1", "Ahmed", "2024-01-01");
    bm.returnBook(lib, "ISBN1", "2024-01-10");

    // Test 2: Edge case - display empty library
    cout << "\n[2] Empty Library:" << endl;
    Library emptyLib;
    emptyLib.displayAll();

    // Test 3: Invalid ISBN
    cout << "\n[3] Invalid ISBN:" << endl;
    bm.borrowBook(lib, "WRONG", "Ali", "2024-01-01");

    // Test 4: Borrow same book twice (duplicate)
    cout << "\n[4] Duplicate Borrow:" << endl;
    lib.addBook(new Book("1984", "Orwell", "ISBN2", 1949));
    bm.borrowBook(lib, "ISBN2", "Ahmed", "2024-01-01");
    bm.borrowBook(lib, "ISBN2", "Omar",  "2024-01-02");

    // Test 5: Remove a borrowed book (should fail)
    cout << "\n[5] Remove Borrowed Book:" << endl;
    lib.removeBook("ISBN2");

    cout << "\n===== DONE =====" << endl;
    return 0;
}