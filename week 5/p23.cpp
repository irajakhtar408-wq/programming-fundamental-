#include <iostream>
using namespace std;

 main() 
{
    int number, digit;
    int count = 0;

    cout << "Enter the number: ";
    cin >> number;

    cout << "Enter the digit to find frequency: ";
    cin >> digit;

    while (number != 0) 
    {
        int lastDigit = number % 10;

        if (lastDigit == digit) 
        {
            count++;
        }

        number = number / 10;
    }

    cout << "Frequency: " << count << endl;

    
}