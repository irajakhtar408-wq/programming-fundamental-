#include<iostream>
using namespace std;
main()
{
cout<<"enter voltage :";
int voltage;
cin>> voltage;

cout<<" enter current (in amp):";
float current;
cin>> current;
double power;
power = voltage * current;
cout<<"the power is" <<power <<"watts";
}