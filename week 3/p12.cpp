#include <iostream>
using namespace std;

main()
 {
    double hours;
    
    cout << "Enter hours: ";
    cin >> hours;

    double seconds = hours * 60 * 60;

    cout << hours << " hour(s) = " << seconds << " seconds" ;

    
}