#include <iostream>
using namespace std;

 main()
{
    int arr[5];
    cout << "Enter 5 elements:" << endl;

    for(int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }

    cout << "1st element is: " << arr[0] << endl;
    cout << "Last element is: " << arr[4] << endl;

    return 0;
}