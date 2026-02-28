#include <iostream>
using namespace std;
 main() {
    
    string movieName;
    double adultPrice;
    double childPrice;
    double donationPercent;
    int adultSold;
     int childSold;

    
    cout << "Enter the movie name: ";
    cin >> movieName;
    cout << "Enter the adult ticket price: $";
    cin >> adultPrice;

    cout << "Enter the child ticket price: $";
    cin >> childPrice;

    cout << "Enter the number of adult tickets sold: ";
    cin >> adultSold;

    cout << "Enter the number of child tickets sold: ";
    cin >> childSold;

    cout << "Enter the percentage of amount to be donated to charity: ";
    cin >> donationPercent;

    
    double totalAmount = (adultPrice * adultSold) + (childPrice * childSold);
    double donationAmount = totalAmount * (donationPercent / 100);
    double remainingAmount = totalAmount - donationAmount;

    cout << "---------------------------------------------------" << endl;
    cout << "Movie: " << movieName << endl;
    cout << "Total Amount Generated from ticket sales: $" << totalAmount << endl;
    cout << "Donation to charity(" << donationPercent << "): $" << donationAmount << endl;
    cout << "Remaining amount after donation: $" << remainingAmount ;

    
}