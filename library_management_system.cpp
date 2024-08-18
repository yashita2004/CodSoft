#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
public:
    Book(const string& title, const string& author)
        : title(title), author(author), issued(false) {}

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    bool isIssued() const { return issued; }

    void issueBook() { issued = true; }
    void returnBook() { issued = false; }

private:
    string title;
    string author;
    bool issued;
};

class Borrower {
public:
    Borrower(const string& name) : name(name) {}

    string getName() const { return name; }

private:
    string name;
};

class Transaction {
public:
    Transaction(const Book& book, const Borrower& borrower, const string& type)
        : book(book), borrower(borrower), type(type) {}

    void showTransaction() const {
        cout << "Transaction: " << type << " - Book: " << book.getTitle() << " by " << book.getAuthor() << ", Borrower: " << borrower.getName() << '\n';
    }

private:
    Book book;
    Borrower borrower;
    string type;
};

class Library {
public:
    void addBook(const string& title, const string& author) {
        books.push_back(Book(title, author));
        cout << "Book added: " << title << " by " << author << '\n';
    }

    void addBorrower(const string& name) {
        borrowers.push_back(Borrower(name));
        cout << "Borrower added: " << name << '\n';
    }

    void viewBooks() const {
        if (books.empty()) {
            cout << "No books in the library.\n";
            return;
        }

        cout << "List of books:\n";
        for (size_t i = 0; i < books.size(); ++i) {
            cout << i + 1 << ". " << books[i].getTitle() << " by " << books[i].getAuthor();
            if (books[i].isIssued()) {
                cout << " (Issued)";
            }
            cout << '\n';
        }
    }

    void viewBorrowers() const {
        if (borrowers.empty()) {
            cout << "No borrowers in the system.\n";
            return;
        }

        cout << "List of borrowers:\n";
        for (size_t i = 0; i < borrowers.size(); ++i) {
            cout << i + 1 << ". " << borrowers[i].getName() << '\n';
        }
    }
     void issueBook(int bookIndex, int borrowerIndex) {
        if (bookIndex < 1 || bookIndex > books.size()) {
            cout << "Invalid book number!\n";
            return;
        }
        if (borrowerIndex < 1 || borrowerIndex > borrowers.size()) {
            cout << "Invalid borrower number!\n";
            return;
        }

        if (books[bookIndex - 1].isIssued()) {
            cout << "Book is already issued.\n";
        } else {
            books[bookIndex - 1].issueBook();
            transactions.push_back(Transaction(books[bookIndex - 1], borrowers[borrowerIndex - 1], "Issue"));
            cout << "Book issued: " << books[bookIndex - 1].getTitle() << " to " << borrowers[borrowerIndex - 1].getName() << '\n';
        }
    }

    void returnBook(int bookIndex, int borrowerIndex) {
        if (bookIndex < 1 || bookIndex > books.size()) {
            cout << "Invalid book number!\n";
            return;
        }
        if (borrowerIndex < 1 || borrowerIndex > borrowers.size()) {
            cout << "Invalid borrower number!\n";
            return;
        }

        if (books[bookIndex - 1].isIssued()) {
            books[bookIndex - 1].returnBook();
            transactions.push_back(Transaction(books[bookIndex - 1], borrowers[borrowerIndex - 1], "Return"));
            cout << "Book returned: " << books[bookIndex - 1].getTitle() << " by " << borrowers[borrowerIndex - 1].getName() << '\n';
        } else {
            cout << "Book was not issued.\n";
        }
    }



    void viewTransactions() const {
        if (transactions.empty()) {
            cout << "No transactions available.\n";
            return;
        }

        cout << "List of transactions:\n";
        for (const auto& transaction : transactions) {
            transaction.showTransaction();
        }
    }

private:
    vector<Book> books;
    vector<Borrower> borrowers;
    vector<Transaction> transactions;
};

int main() {
    Library library;
    int choice;

    do {
        cout << "\nLibrary Management System:\n";
        cout << "1. Add Book\n";
        cout << "2. Add Borrower\n";
        cout << "3. View Books\n";
        cout << "4. View Borrowers\n";
        cout << "5. Issue Book\n";
        cout << "6. Return Book\n";
        cout << "7. View Transactions\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cin.ignore(); 
            string title, author;
            cout << "Enter book title: ";
            getline(cin, title);
            cout << "Enter book author: ";
            getline(cin, author);
            library.addBook(title, author);
            break;
        }
        case 2: {
            cin.ignore(); 
            string name;
            cout << "Enter borrower name: ";
            getline(cin, name);
            library.addBorrower(name);
            break;
        }
        case 3:
            library.viewBooks();
            break;
        case 4:
            library.viewBorrowers();
            break;
        case 5: {
            int bookNumber, borrowerNumber;
            cout << "Enter book number to issue: ";
            cin >> bookNumber;
            cout << "Enter borrower number: ";
            cin >> borrowerNumber;
            library.issueBook(bookNumber, borrowerNumber);
            break;
        }
        case 6: {
            int bookNumber, borrowerNumber;
            cout << "Enter book number to return: ";
            cin >> bookNumber;
            cout << "Enter borrower number: ";
            cin >> borrowerNumber;
            library.returnBook(bookNumber, borrowerNumber);
            break;
        }
        case 7:
            library.viewTransactions();
            break;
        case 8:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}
