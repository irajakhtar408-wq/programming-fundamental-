#include <iostream>
using namespace std;

 main()
{
    int number;
    int count = 0;

    cout << "Enter a number: ";
    cin >> number;

    while (number != 0)
    {
        number = number / 10;
        count++;
    }

    cout << "Total digits = " << count << endl;

    return 0;
}