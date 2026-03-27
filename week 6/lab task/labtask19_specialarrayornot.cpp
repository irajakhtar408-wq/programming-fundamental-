#include <iostream>
using namespace std;

bool isSpecialArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        if (i % 2 == 0)
         {
    
            if (arr[i] % 2 != 0) return false;
        } else 
        {
            
            if (arr[i] % 2 == 0) return false;
        }
    }
    return true;
}

int main() 
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];
    cout << "Enter " << size << " elements of the array:" << endl;
    for (int i = 0; i < size; i++) 
    {

        cin >> arr[i];
    }

    if (isSpecialArray(arr, size)) 
    {
        cout << "The array is special" << endl;
    } else 
    {
        cout << "The array is not special" << endl;
    }

    return 0;
}