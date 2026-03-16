#include <iostream>
using namespace std;

 main() {
    int age, washingMachinePrice, toyPrice;
    cout<<"enter lily age :";
    cin >> age;    
    cout<<"enter price of washing machine :" ;           
    cin >> washingMachinePrice;
    cout<<"enter the toy price :";
    cin >> toyPrice;          

    int moneySaved = 0;
    int toyCount = 0;
    int moneyFromBirthdays = 0;
    int totalToysMoney = 0;

    for (int i = 1; i <= age; i++) 
    {
        if (i % 2 == 0) 
        {
             
            moneyFromBirthdays += 10 * (i / 2); 
            moneyFromBirthdays -= 1;            
        } else 
        {
            
            toyCount++;
        }
    }

    totalToysMoney = toyCount * toyPrice;
    moneySaved = moneyFromBirthdays + totalToysMoney;

    if (moneySaved >= washingMachinePrice)
     {
        cout << "Yes! " << moneySaved - washingMachinePrice << endl;
    } else 
    {
        cout << "No! " << washingMachinePrice - moneySaved << endl;
    }

    return 0;
}