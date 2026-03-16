#include <iostream>
using namespace std;

 main() 
 {
    
    long num, temp;
    int digit, count;

    cout << "Enter a number: ";
    cin >> num;

    for(int i = 0; i <= 9; i++) {
        temp = num;
        count = 0;

        for(; temp > 0; temp = temp / 10) 
        {
            digit = temp % 10;

            if(digit == i) {
                count++;
            }
        }

        if(count > 0)
         {
            cout << "Digit " << i << " = " << count << endl;
        }
    }

    
}