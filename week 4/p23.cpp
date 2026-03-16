
#include <iostream>
using namespace std;

 main()
{
    int num;
    cout << "Enter number (0-100): ";
    cin >> num;

    if (num == 100)
    {
        cout << "one hundred";
    }
    else if (num >= 20 && num <= 99)
    {
        int tens = num / 10;
        int ones = num % 10;

        if (tens == 2) cout << "twenty";
        else if (tens == 3) cout << "thirty";
        else if (tens == 4) cout << "forty";
        else if (tens == 5) cout << "fifty";
        else if (tens == 6) cout << "sixty";
        else if (tens == 7) cout << "seventy";
        else if (tens == 8) cout << "eighty";
        else if (tens == 9) cout << "ninety";

        if (ones == 1) cout << " one";
        else if (ones == 2) cout << " two";
        else if (ones == 3) cout << " three";
        else if (ones == 4) cout << " four";
        else if (ones == 5) cout << " five";
        else if (ones == 6) cout << " six";
        else if (ones == 7) cout << " seven";
        else if (ones == 8) cout << " eight";
        else if (ones == 9) cout << " nine";
    }
    else if (num >= 10 && num <= 19)
    {
        if (num == 10) cout << "ten";
        else if (num == 11) cout << "eleven";
        else if (num == 12) cout << "twelve";
        else if (num == 13) cout << "thirteen";
        else if (num == 14) cout << "fourteen";
        else if (num == 15) cout << "fifteen";
        else if (num == 16) cout << "sixteen";
        else if (num == 17) cout << "seventeen";
        else if (num == 18) cout << "eighteen";
        else if (num == 19) cout << "nineteen";
    }
    else if (num >= 0 && num <= 9)
    {
        if (num == 0) cout << "zero";
        else if (num == 1) cout << "one";
        else if (num == 2) cout << "two";
        else if (num == 3) cout << "three";
        else if (num == 4) cout << "four";
        else if (num == 5) cout << "five";
        else if (num == 6) cout << "six";
        else if (num == 7) cout << "seven";
        else if (num == 8) cout << "eight";
        else if (num == 9) cout << "nine";
    }
    else
    {
        cout << "Out of range";
    }

    
}