#include <iostream>
using namespace std;

void calculateSum(int arr[], int size) 
{
    int sum = 0;
    for (int i = 0; i < size; i++) 
    {
        sum += arr[i];
    }
    cout << "The sum of all elements is: " << sum << endl;
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

    
    calculateSum(arr, n);

    return 0;
}