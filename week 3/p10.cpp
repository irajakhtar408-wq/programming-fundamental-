#include<iostream>
using namespace std;
main()
{
cout<<"enter charge (Q) :";
int charge;
cin>> charge;
cout<<"enter time (t) :";
int time;
cin>> time;
float current;
current = charge /time;
cout<<" the current I :"<<current;
}