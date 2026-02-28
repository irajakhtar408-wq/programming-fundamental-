#include <iostream>
using namespace std;

main() 
{ 
    cout << "enter minutes : ";
    int minutes;
    cin >> minutes;

    cout << "enter farmer per second : ";
    int farmer;
    cin >> farmer;

    int total;
    total = minutes * 60 * farmer; 

    
    cout << "total number of farmer : " << total ;

    
}