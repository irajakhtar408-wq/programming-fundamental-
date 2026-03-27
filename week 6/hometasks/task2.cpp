#include <iostream>
using namespace std;

void countEvenNumbers(int arr[], int size) 
{
    int count = 0;
    for (int i = 0; i < size; i++) 
    {
        if (arr[i] % 2 == 0)
         {
            count++;
        }
    }
    cout << "The number of even elements is: " << count << endl;
}

int main() 
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n]; 

    cout << "Enter " << n << " numbers:" << endl;
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }

    
    countEvenNumbers(arr, n);

    return 0;
}