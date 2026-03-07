#include <iostream>
using namespace std;

 main()
{
    int redRose, whiteRose, tulips;
    double totalPrice, finalPrice;

    
    double redPrice = 2.00;
    double whitePrice = 4.10;
    double tulipPrice = 2.50;

    
    cout << "Enter number of Red Roses: ";
    cin >> redRose;

    cout << "Enter number of White Roses: ";
    cin >> whiteRose;

    cout << "Enter number of Tulips: ";
    cin >> tulips;


    totalPrice = (redRose * redPrice) + (whiteRose * whitePrice) + (tulips * tulipPrice);

    cout << "Original Price: $" << totalPrice ;

     if(totalPrice > 200) 
     
    {
        finalPrice = totalPrice - (totalPrice * 0.20);
        cout <<  "Discount Applied!" << finalPrice ;
    }
    else
    {
        cout << " Discount Amount: $" << totalPrice << endl;
    }
}