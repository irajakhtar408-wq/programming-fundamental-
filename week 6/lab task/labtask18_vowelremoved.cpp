#include <iostream>
using namespace std;

string removeVowels(const string &input)
 {
    string result = "";
    for (char c : input) 
    {
        
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' &&
            c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U') 
            {
            result += c; 
        }
    }
    return result;
}

int main() 
{
    string text;
    cout << "Enter a string: ";
    getline(cin, text); 

    string noVowels = removeVowels(text);
    cout << "String without vowels: " << noVowels << endl;

    return 0;
}