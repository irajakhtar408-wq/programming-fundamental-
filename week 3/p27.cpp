#include <iostream>
using namespace std;
 main()
 {

    int age, moves;
    double average;

    cout << "Enter your age: ";
    cin >> age;

    cout << "Enter number of times you moved: ";
    cin >> moves;

    
    average = age / (moves + 1);

    cout << "Average years spent in one house: " << average ;

    
}