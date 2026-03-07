#include<iostream>
using namespace std;
main()
{
    string countryname;
    cout<<"enetr the country name :";
    cin>> countryname;
    int ticketprice;
    cout<<"enter ticker price in dollar :";
    cin>> ticketprice;
    float dicountedprice;
    if(countryname =="ireland") 
    {
                    dicountedprice= ticketprice*10/100;
               cout<<" dicountedprice is  " <<dicountedprice;
                }
              if(countryname!="ireland")
              {
        dicountedprice = ticketprice*5/100;
     cout<<" dicountedprice is  " <<dicountedprice;                                       }
    }