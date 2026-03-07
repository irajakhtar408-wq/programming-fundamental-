
#include <iostream>
using namespace std;

 main()
{
    int num;

    cout << "Enter a number (0 - 100): ";
    cin >> num;

    if (num >= 0 && num <= 9)
    {
        string ones[] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
        cout << ones[num];
    }
    else if (num >= 10 && num <= 19)
    {
        string teens[] = {"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
        cout << teens[num - 10];
    }
    else if (num >= 20 && num <= 99)
    {
        string tens[] = {"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
        string ones[] = {"","one","two","three","four","five","six","seven","eight","nine"};

        cout << tens[num / 10];
        if (num % 10 != 0)
        {
            cout << " " << ones[num % 10];
        }
    }
    else if (num == 100)
    {
        cout << "one hundred";
    }

    
}