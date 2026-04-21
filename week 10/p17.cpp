#include <iostream>
using namespace std;

// Global variable
int x = 10;

void display()
{
    // Local variable
    int x = 20;

    cout << "Inside display() function (Local x): " << x << endl;
}

int main()
{
    cout << "Inside main() before function call (Global x): " << x << endl;

    display();

    cout << "Inside main() after function call (Global x): " << x << endl;

    return 0;
}