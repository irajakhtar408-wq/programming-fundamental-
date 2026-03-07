#include<iostream>
using namespace std;
main()
{
    int num,even;
    cout<<"enter the number :";
    cin>>num;
    even=num%2;
    if(num==0)
    {
        cout<<"number is even";
    }
    else{
        cout<<"number is odd";
    }
}