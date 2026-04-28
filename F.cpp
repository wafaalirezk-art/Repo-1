#include <iostream>
#include <vector>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool isBorrowed;

    Book(int i, string t, string a) {
        id = i;
        title = t;
        author = a;
        isBorrowed = false;
    }
};

class Library {
private:
    vector<Book> books;
    vector<Book> myBooks;

public:
    void addBook() {
        int id;
        string title, author;

        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Title: ";
        getline(cin, title);
        cout << "Enter Author: ";
        getline(cin, author);

        books.push_back(Book(id, title, author));
        cout << "Book added successfully!\n";
    }

    void viewBooks() {
        cout << "\nAvailable Books:\n";
        for (auto &b : books) {
            if (!b.isBorrowed)
                cout << b.id << " - " << b.title << " by " << b.author << endl;
        }
    }

    void borrowBook() {
        int id;
        cout << "Enter Book ID to borrow: ";
        cin >> id;

        for (auto &b : books) {
            if (b.id == id && !b.isBorrowed) {
                b.isBorrowed = true;
                myBooks.push_back(b);
                cout << "Book borrowed!\n";
                return;
            }
        }
        cout << "Book not available!\n";
    }

    void returnBook() {
        int id;
        cout << "Enter Book ID to return: ";
        cin >> id;

        for (auto &b : books) {
            if (b.id == id && b.isBorrowed) {
                b.isBorrowed = false;

                for (int i = 0; i < myBooks.size(); i++) {
                    if (myBooks[i].id == id) {
                        myBooks.erase(myBooks.begin() + i);
                        break;
                    }
                }

                cout << "Book returned!\n";
                return;
            }
        }
        cout << "Invalid ID!\n";
    }

    void myBorrowedBooks() {
        cout << "\nMy Books:\n";
        for (auto &b : myBooks) {
            cout << b.id << " - " << b.title << endl;
        }
    }
};

int main() {
    Library lib;
    int choice;

    do {
        cout << "\n--- Library Menu ---\n";
        cout << "1. View Books\n2. Borrow Book\n3. Return Book\n";
        cout << "4. My Books\n5. Add Book\n0. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1: lib.viewBooks(); break;
            case 2: lib.borrowBook(); break;
            case 3: lib.returnBook(); break;
            case 4: lib.myBorrowedBooks(); break;
            case 5: lib.addBook(); break;
        }
    } while (choice != 0);

    return 0;
}