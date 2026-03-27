#include <iostream>
using namespace std;

int main()
{
    int quarters, dimes, nickels, pennies;
    float totalDue;
    float totalMoney = 0;

    cout << "Enter quarters: ";
    cin >> quarters;

    cout << "Enter dimes: ";
    cin >> dimes;

    cout << "Enter nickels: ";
    cin >> nickels;

    cout << "Enter pennies: ";
    cin >> pennies;

    cout << "Enter the total amount due: $";
    cin >> totalDue;

    
    totalMoney = (quarters * 0.25) +
                 (dimes * 0.10) +
                 (nickels * 0.05) +
                 (pennies * 0.01);

    
    cout << "Can you pay the amount? ";

    if(totalMoney >= totalDue)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}