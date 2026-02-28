#include <iostream>
using namespace std;
 main()
 {
    
    string name;
    float target_Weight;
    float days_Needed;

    
    cout << "Enter the Name of the Person: ";
    cin>> name;

    cout << "Enter the target weight loss in kilograms: ";
    cin >> target_Weight;

  
    days_Needed = target_Weight * 15;

    
    cout << name << " will need " << days_Needed << " days to lose"<< target_Weight << " kg of weight by following the doctor's suggestions" ;

    
}