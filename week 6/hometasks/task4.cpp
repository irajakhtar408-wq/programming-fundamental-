#include <iostream>

using namespace std;

 main()
 {
    const int SIZE = 5;   
    string students[SIZE];

    cout << "Enter the names of 5 students:" ;
    for (int i = 0; i < SIZE; i++) 
    {
        cout << "Student " << (i + 1) << ": ";
        getline(cin, students[i]);  
    }

    cout << "\nList of students:" << endl;
    for (int i = 0; i < SIZE; i++) 
    {
        cout << students[i] << endl;
    }

    return 0;
}