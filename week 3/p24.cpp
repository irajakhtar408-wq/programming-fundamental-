#include <iostream>
using namespace std;
main()
 {
   
    double vegPricePerKg;
    double fruitPricePerKg;
    int totalKgVeg;
     int  totalKgFruit;

    
    cout << "Enter vegetable price per kilogram (in coins): ";
    cin >> vegPricePerKg;

    cout << "Enter fruit price per kilogram (in coins): ";
    cin >> fruitPricePerKg;

    cout << "Enter total kilograms of vegetables: ";
    cin >> totalKgVeg;

    cout << "Enter total kilograms of fruits: ";
    cin >> totalKgFruit;

      double totalCoins;
      
        totalCoins = (vegPricePerKg * totalKgVeg) + (fruitPricePerKg * totalKgFruit);

     double totalRupees ;
          totalRupees = totalCoins / 1.94;

    cout << "Total earnings in Rupees (Rps): " << totalRupees ;

    
}