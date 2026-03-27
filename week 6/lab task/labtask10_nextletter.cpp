#include <iostream>
using namespace std;

 main()
{
    string str;

    
    cout << "Enter a string: ";
    cin >> str;

    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == 'z')
            str[i] = 'a';
        else if(str[i] == 'Z')
            str[i] = 'A';
        else
            str[i] = str[i] + 1;
    }

    cout << "Output: " << str << endl;

    return 0;
}