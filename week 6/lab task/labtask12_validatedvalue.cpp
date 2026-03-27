#include <iostream>
using namespace std;

 main()
{
    int n;
    int arr[50];

    cout << "Enter how many numbers: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cout << "Enter number: ";
        cin >> arr[i];

        
        for(int j = 0; j < i; j++)
        {
            if(arr[i] == arr[j])
            {
                cout << "Already Entered" << endl;
                break;
            }
        }
    }

    return 0;
}