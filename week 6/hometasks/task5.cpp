#include <iostream>
using namespace std;

void countNamesWithLetter(string arr[], int size, char letter) 
{
    int count = 0;
    for (int i = 0; i < size; i++) 
    {
        
        if (arr[i].find(letter) != string::npos) 
        {
            count++;
        }
    }
    cout << "Number of names containing '" << letter << "': " << count << endl;
}

int main() 
{
    int n;
    cout << "Enter the number of customers: ";
    cin >> n;
    cin.ignore(); 

    string customers[n];
    cout << "Enter the names of " << n << " customers:" << endl;
    for (int i = 0; i < n; i++)
     {
        cout << "Customer " << (i + 1) << ": ";
        getline(cin, customers[i]);
    }

    char letter;
    cout << "Enter a letter to search: ";
    cin >> letter;

    countNamesWithLetter(customers, n, letter);

    return 0;
}