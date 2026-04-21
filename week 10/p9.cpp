#include <iostream>
using namespace std;

string checkNumber(int num)
{
    int sum = 0;

    while(num > 0)
    {
        sum += num % 10;
        num /= 10;
    }

    if(sum % 2 == 0)
        return "Evenish";
    else
        return "Oddish";
}

int main()
{
    int num;
    cout << "Enter 5-digit number: ";
    cin >> num;

    cout << checkNumber(num);

    return 0;
}