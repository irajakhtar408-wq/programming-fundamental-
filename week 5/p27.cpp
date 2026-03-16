#include <iostream>
using namespace std;

 main() 
 {

    double money;
    int year;
    cout<<"enter money :";
    cin >> money;
   cout<<"enter yer :";
    cin >> year;

    int age = 18;
    double spent = 0;

    for(int y = 1800; y <= year; y++)
     {

        if(y % 2 == 0) 
        {
            spent += 12000;
        }
        else 
        {
            spent += 12000 + 50 * age;
        }

        age++;
    }

    if(money >= spent) 
    {
        cout << "Yes! He will live a carefree life and will"<< money - spent << " dollars left." << endl;
    }
    else 
    {
        cout << "He will need " << spent - money << " dollars to survive." << endl;
    }

    return 0;
}

