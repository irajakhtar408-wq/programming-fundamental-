
#include <iostream>
using namespace std;
 main() 
 {
    int choice;

    while (true) 
    {
        
        cout << "\n--- Restaurant Management System ---\n";
        cout << "1. View Food Menu\n";
        cout << "2. Place Order\n";
        cout << "3. View Order Status\n";
        cout << "4. Generate Bill\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) 
        {
            cout << "You selected: View Food Menu.\n";
        }
        else if (choice == 2) 
        {
            cout << "You selected: Place Order.\n";
        }
        else if (choice == 3) 
        {
            cout << "You selected: View Order Status.\n";
        }
        else if (choice == 4) 
        {
            cout << "You selected: Generate Bill.\n";
        }
        else if (choice == 5)
         {
            cout << "Exiting... Thank you!\n";

        }
        else
         {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    
}