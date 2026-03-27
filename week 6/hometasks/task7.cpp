#include <iostream>
#include <iomanip>
using namespace std;

struct Product 
{
    string name;
    double price;
    int quantity;
};

 main() 
{
    int n;
    cout << "Enter number of products: ";
    cin >> n;
    cin.ignore(); 

    Product products[n];

    for (int i = 0; i < n; i++)
     {
        cout << "\nEnter name of product " << (i + 1) << ": ";
        getline(cin, products[i].name);

        cout << "Enter price of " << products[i].name << ": $";
        cin >> products[i].price;

        cout << "Enter quantity of " << products[i].name << ": ";
        cin >> products[i].quantity;
        cin.ignore(); 
    }

    
    cout << "\nProduct Inventory Report\n";
    cout << "------------------------\n";
    cout << fixed << setprecision(2); 

    for (int i = 0; i < n; i++) 
    {
        double totalValue = products[i].price * products[i].quantity;
        cout << products[i].name << ": $" << products[i].price
             << ", " << products[i].quantity << " in stock, "
             << "Total value: $" << totalValue << endl;
    }

    return 0;
}