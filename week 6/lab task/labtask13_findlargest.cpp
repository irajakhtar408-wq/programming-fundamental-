#include <iostream>
using namespace std;
int findLargest(int arr[], int n);
 main()
{
    int n;
    int arr[50];

    cout << "Enter size: ";
    cin >> n;

    cout << "Enter numbers: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int largest = findLargest(arr, n);

    cout << "Largest number is: " << largest << endl;

    return 0;
}

int findLargest(int arr[], int n)
{
    int max = arr[0];

    for(int i = 1; i < n; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}