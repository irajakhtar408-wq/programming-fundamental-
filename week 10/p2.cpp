#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int base, exponent;

    cout << "Enter base: ";
    cin >> base;

    cout << "Enter exponent: ";
    cin >> exponent;

    double result = pow(base, exponent);

    cout << "Result = " << result;

    return 0;
}