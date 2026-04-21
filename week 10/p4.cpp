#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double distance, angle, height;

    cout << "Enter distance (feet): ";
    cin >> distance;

    cout << "Enter angle (degrees): ";
    cin >> angle;

    // Convert to radians
    double radians = angle / 57.2958;

    height = distance * tan(radians);

    cout << "Height of tree = " << height << " feet";

    return 0;
}