#include <iostream>
using namespace std;

int main() {
    int num1, num2, gcd, lcm;

    cout << "Enter  numbers: ";
    cin>> num1;
    cout<<"Enter second number :";
    cin >> num2;

    
    for (int i = 1; i <= num1 && i <= num2; i++)
     {
        if (num1 % i == 0 && num2 % i == 0)
         {
            gcd = i;
        }
    }

    lcm = (num1 * num2) / gcd;

    cout << "GCD (HCF) = " << gcd << endl;
    cout << "LCM = " << lcm << endl;

    return 0;
}
