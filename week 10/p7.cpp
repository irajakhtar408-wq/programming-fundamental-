#include <iostream>
using namespace std;

string checkAlphabetCase(char ch)
{
    if(ch == 'A')
        return "You have entered Capital A";
    else
        return "You have entered small a";
}

int main()
{
    char ch;
    cout << "Enter A or a: ";
    cin >> ch;

    cout << checkAlphabetCase(ch);

    return 0;
}