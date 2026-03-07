#include <iostream>
using namespace std;

int main()
{
    string figure;
    double area;

    cout << "Enter figure type (square, rectangle, circle, triangle): ";
    cin >> figure;

    if (figure == "square")
    {
        double s;
        cout << "Enter side: ";
        cin >> s;

        area = s * s;
        cout << "Area = " << area;
    }
    else if (figure == "rectangle")
    {
        double l, w;
        cout << "Enter length: ";
        cin >> l;

        cout << "Enter width: ";
        cin >> w;

        area = l * w;
        cout << "Area = " << area;
    }
    else if (figure == "circle")
    {
        double r;
        cout << "Enter radius: ";
        cin >> r;

        area = 3.1416 * r * r;
        cout << "Area = " << area;
    }
    else if (figure == "triangle")
    {
        double b, h;
        cout << "Enter base: ";
        cin >> b;

        cout << "Enter height: ";
        cin >> h;

        area = 0.5 * b * h;
        cout << "Area = " << area;
    }

    
}