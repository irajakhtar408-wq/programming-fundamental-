#include <iostream>

using namespace std;

int main() {
    
    float bagSize;
    float bagCost;
   float areaCovered;
    float costPerPound;
    float costPerSquareFoot;

    cout << "Enter the size of the fertilizer bag in pounds: ";
    cin >> bagSize;

    cout << "Enter the cost of the bag: ";
    cin >> bagCost;

    cout << "Enter the area in square feet that can be covered by the bag: ";
    cin >> areaCovered;

   
    costPerPound = bagCost / bagSize;
    costPerSquareFoot = bagCost / areaCovered;

    
    cout << "Cost of fertilizer per pound: " << costPerPound << endl;
    cout << "Cost of fertilizing per square foot: $" << costPerSquareFoot << endl;

    
}