#include<iostream>
using namespace std;
main()
{
cout<<"enter intitial_velocity : ";
int intitial_velocity;
cin>> intitial_velocity;

cout<<" enter acceleration  : ";
int acceleration ;
cin>> acceleration;

cout<<" enter time :";
int time ;
cin>> time;

int final_velocity;
final_velocity = intitial_velocity +(acceleration *time);
cout<<"the final velocity of toy car is: " <<final_velocity;
}