#include<iostream>
using namespace std;
main()
{
    char ch;
    cout<<"enter any character in lower case : ";
    cin>> ch;
    if(ch=='a'|| ch=='e' || ch=='i' || ch=='o' || ch=='u')
{
    cout<<"it is a vowel";
}else if(ch>=0 && ch<=9)
{
cout<<"it is a number ";
}else
{
    cout<<"it is a consonant";
}
}