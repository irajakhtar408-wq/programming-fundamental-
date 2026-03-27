#include <iostream>
using namespace std;

const int MAX_BOOKS = 100; 

string bookTitles[MAX_BOOKS];
int bookQuantity[MAX_BOOKS];
int bookCount = 0; 


void addBooks() {
    int n;
    cout << "How many books do you want to add? ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        if (bookCount >= MAX_BOOKS) {
            cout << "Library is full!" << endl;
            break;
        }
        cout << "Enter title of book " << (i + 1) << ": ";
        getline(cin, bookTitles[bookCount]);
        cout << "Enter quantity of \"" << bookTitles[bookCount] << "\": ";
        cin >> bookQuantity[bookCount];
        cin.ignore();
        bookCount++;
    }
}


void viewBooks() 
{
    if (bookCount == 0)
     {
        cout << "No books in the library." << endl;
        return;
    }
    cout << "\nBooks in Library:\n";
    cout << "-----------------\n";
    for (int i = 0; i < bookCount; i++) {
        cout << i + 1 << ". " << bookTitles[i] 
             << " (Quantity: " << bookQuantity[i] << ")" << endl;
    }
}

void borrowBook() {
    if (bookCount == 0) 
    {
        cout << "No books available to borrow." << endl;
        return;
    }
    int choice;
    viewBooks();
    cout << "Enter the number of the book you want to borrow: ";
    cin >> choice;

    if (choice < 1 || choice > bookCount) {
        cout << "Invalid choice!" << endl;
    } else {
        if (bookQuantity[choice - 1] > 0) 
        {
            bookQuantity[choice - 1]--;
            cout << "You borrowed \"" << bookTitles[choice - 1] << "\" successfully." << endl;
        } else 
        {
            cout << "Sorry, \"" << bookTitles[choice - 1] << "\" is out of stock." << endl;
        }
    }
}

int main() {
    int option;
    do {
        cout << "\nLibrary Menu:\n";
        cout << "1. Add Books\n";
        cout << "2. View Books\n";
        cout << "3. Borrow Books\n";
        cout << "4. View Books\n"; 
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> option;
        cin.ignore();

        switch (option)
         {
            case 1: addBooks(); break;
            case 2: viewBooks(); break;
            case 3: borrowBook(); break;
            case 4: viewBooks(); break;
            case 5: cout << "Exiting program..." << endl; break;
            default: cout << "Invalid choice, try again." << endl;
        }
    } while (option != 5);

    return 0;
}