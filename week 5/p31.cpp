#include <iostream>
using namespace std;
 main() 
 {
    int choice;

    while (true) 
    {
        
        cout << "\n--- Library Management System ---\n";
        cout << "1. View Available Books\n";
        cout << "2. Borrow Book\n";
        cout << "3. Return Book\n";
        cout << "4. Search Book\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        
        if (choice == 1) 
        {
            cout << "You selected: View Available Books.\n";
        }
        else if (choice == 2)
         {
            cout << "You selected: Borrow Book.\n";
        }
        else if (choice == 3)
         {
            cout << "You selected: Return Book.\n";
        }
        else if (choice == 4)
         {
            cout << "You selected: Search Book.\n";
        }
        else if (choice == 5)
         {
            cout << "Exiting Library System. Goodbye!\n";
            break; 
        }
        else
         {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    
}