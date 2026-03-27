#include <iostream>
using namespace std;

 main()
{
    string str;
    char ch;
    bool found = false;

    cout << "Enter a string: ";
    cin >> str;

    cout << "Enter a character to search: ";
    cin >> ch;

    
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == ch)
        {
            found = true;
            break;
        }
    }

    
    if(found)
        cout << "Character is present in the string." << endl;
    else
        cout << "Character is not present in the string." << endl;

    return 0;
}