#include<iostream>
using namespace std;
main()
{
cout<< "enter the student name :";
string name ;
cin>>name;
cout<<"enter the matric mark (out of 1100)  :";
int matric_marks ;
cin>> matric_marks;
cout<<" enter you intermediate mark ( out of 50) : ";
int intermediate_mark;
cin>> intermediate_mark;
cout<<"enter your Ecat mark (out of 400) :";
int ecat_mark;
cin>> ecat_mark;
float aggragate;
aggragate = (matric_marks*0.10)+(intermediate_mark*0.40)+(ecat_mark*0.50);
cout<<"aggragate score for "<<name<<aggragate;
}