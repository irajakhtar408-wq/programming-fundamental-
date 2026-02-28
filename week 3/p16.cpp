#include <iostream>
using namespace std;

 main() {
    int currentPopulation;
    int monthlyBirthRate;

    cout << "Enter the current world population: ";
    cin >> currentPopulation;

    cout << "Enter the monthly birth rate (number of births per month): ";
    cin >> monthlyBirthRate;

    int populationInThreeDecades = currentPopulation + (monthlyBirthRate * 360);

    cout << "Population in three decades will be: " << populationInThreeDecades ;

   
}