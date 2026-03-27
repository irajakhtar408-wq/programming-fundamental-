#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;
    cin.ignore();

    string students[n];
    cout << "Enter the names of " << n << " students:" << endl;
    for (int i = 0; i < n; i++) 
    {
        cout << "Student " << (i + 1) << ": ";
        getline(cin, students[i]);
    }

    sort(students, students + n);


    cout << "\nNames in alphabetical order:" << endl;
    for (int i = 0; i < n; i++) 
    {
        cout << students[i] << endl;
    }

    return 0;
}