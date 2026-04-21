#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a, b, c, d;

    cout << "Enter a, b, c: ";
    cin >> a >> b >> c;

    d = (b*b) - (4*a*c);

    if(d > 0)
    {
        double x1 = (-b + sqrt(d)) / (2*a);
        double x2 = (-b - sqrt(d)) / (2*a);

        cout << "Two real roots: " << x1 << " and " << x2;
    }
    else if(d == 0)
    {
        double x = -b / (2*a);
        cout << "One root: " << x;
    }
    else
    {
        cout << "No real roots (complex)";
    }

    return 0;
}