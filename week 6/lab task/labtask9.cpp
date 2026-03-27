#include <iostream>
using namespace std;


void reverseString(string str)
{
    for(int i = str.length() - 1; i >= 0; i--)
    {
        cout << str[i];
    }
    cout << endl;
}

int main()
{
    string str;

    
    cout << "Enter a string: ";
    cin >> str;

    
    reverseString(str);

    return 0;
}