#include <iostream>
using namespace std;

 main()
{
    int n;

    
    cout << "Enter how many numbers: ";
    cin >> n;

    int arr[n];   

    cout << "Enter " << n << " numbers:" << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "You entered:" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}