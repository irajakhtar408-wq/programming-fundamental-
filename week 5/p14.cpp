
#include <iostream>
using namespace std;

 main()
  {
    int pin;
    int correctPin = 1234;
    int balance = 1000;
    int choice, amount;

    
    for(int i = 1; i <= 3; i++) 
    {
        cout << "Enter ATM PIN: ";
        cin >> pin;

        if(pin == correctPin) 
        {
            cout << "Login Successful\n";

            
            cout << "\n1 -> Check Balance";
            cout << "\n2 -> Deposit Money";
            cout << "\n3 -> Withdraw Money";
            cout << "\n4 -> Exit";
            cout << "\nEnter choice: ";
            cin >> choice;

            if(choice == 1) 
            {
                cout << "Balance = " << balance << endl;
            }
            else if(choice == 2)
             {
                cout << "Enter deposit amount: ";
                cin >> amount;
                balance = balance + amount;
                cout << "New Balance = " << balance << endl;
            }
            else if(choice == 3) 
            {
                cout << "Enter withdraw amount: ";
                cin >> amount;

                if(amount <= balance && amount > 0) {
                    balance = balance - amount;
                    cout << "Remaining Balance = " << balance << endl;
                }
                else {
                    cout << "Insufficient Balance\n";
                }
            }
            else if(choice == 4) 
            {
                cout << "Exit Program\n";
            }
            else {
                cout << "Invalid Choice\n";
            }

            break;
        }
        else {
            cout << "Incorrect PIN\n";
        }
    }

    
}