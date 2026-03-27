#include <iostream>
using namespace std;

 main()
{
    int n;
    float R[50], RT = 0;

    cout << "Enter number of resistors: ";
    cin >> n;

    cout << "Enter resistance values: ";
    for(int i = 0; i < n; i++)
    {
        cin >> R[i];
        RT = RT + R[i];
    }

    cout << "Total Resistance (RT) = " << RT << endl;

    return 0;
}