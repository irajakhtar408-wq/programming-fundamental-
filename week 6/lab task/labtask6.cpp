#include <iostream>
using namespace std;

 main()
{
    int sum = 0;
    float average;

    for(int i = 1; i <= 5; i++)
    {
        sum = sum + i;
    }

    
    average = sum / 5.0;

    cout << "Sum = " << sum << endl;
    cout << "Average = " << average << endl;

    return 0;
}