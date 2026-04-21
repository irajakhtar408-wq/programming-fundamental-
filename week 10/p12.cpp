#include <iostream>
using namespace std;

float taxCalculator(char type, float price)
{
    float taxRate;

    if(type == 'M')
        taxRate = 0.06;
    else if(type == 'E')
        taxRate = 0.08;
    else if(type == 'S')
        taxRate = 0.10;
    else if(type == 'V')
        taxRate = 0.12;
    else if(type == 'T')
        taxRate = 0.15;
    else
        taxRate = 0;

    float finalPrice = price + (price * taxRate);
    return finalPrice;
}

int main()
{
    char type;
    float price;

    cout << "Enter vehicle type: ";
    cin >> type;

    cout << "Enter price: ";
    cin >> price;

    float result = taxCalculator(type, price);

    cout << "Final price of vehicle type " << type << " is $" << result;

    return 0;
}