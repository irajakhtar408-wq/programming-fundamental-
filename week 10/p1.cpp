#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num1, num2;

    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    int result = min(num1, num2);

    cout << "Minimum number is: " << result;

    return 0;
}