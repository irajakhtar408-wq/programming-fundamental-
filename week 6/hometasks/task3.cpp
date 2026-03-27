#include <iostream>
using namespace std;

void findLargestSmallest(int arr[], int size) 
{
    int largest = arr[0];
    int smallest = arr[0];

    for (int i = 1; i < size; i++) 
    {
        if (arr[i] > largest) 
        {
            largest = arr[i];
        }
        if (arr[i] < smallest) 
        {
            smallest = arr[i];
        }
    }

    cout << "The largest number is: " << largest << endl;
    cout << "The smallest number is: " << smallest << endl;
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

    
    findLargestSmallest(arr, n);

    return 0;
}