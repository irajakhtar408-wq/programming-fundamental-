#include <iostream>

using namespace std;

int main()
 {
    int number, digit1, digit2, digit3, digit4, sum;

    
    cout << "Enter a 4-digit number: ";
    cin >> number; 

    
    
    digit4 = number % 10;      
    number = number / 10;      

    digit3 = number % 10;      
    number = number / 10;     


    digit2 = number % 10;      
    number = number / 10;      

    digit1 = number % 10;      

    
    sum = digit1 + digit2 + digit3 + digit4;

    
    cout << "Sum of the individual digits: " << sum ;

    
}