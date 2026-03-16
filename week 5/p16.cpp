#include <iostream>
using namespace std;

 main()
{
    int num = 0,sum = 0;
    while (num>=0)
    {
        sum= sum+num;
        cout<<"enter the number :";
        cin>> num;
    }
    cout<<"sum is :"<<sum;
}