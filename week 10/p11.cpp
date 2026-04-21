#include <iostream>
using namespace std;

string pyramidVolume(double l, double w, double h, string unit)
{
    double volume = (l * w * h) / 3;

    // Convert units
    if(unit == "millimeters")
        volume *= 1000000000;
    else if(unit == "centimeters")
        volume *= 1000000;
    else if(unit == "kilometers")
        volume /= 1000000000;

    return to_string(volume) + " cubic " + unit;
}

int main()
{
    cout << pyramidVolume(4,6,20,"centimeters") << endl;
    return 0;
}