#include <iostream>
using namespace std;

 main()
{
    int holidays;
    int workingDays;
    int totalMinutes;
    int norm = 30000;
    int difference;
    int hours, minutes;

    cout << "Enter number of holidays: ";
    cin >> holidays;

    workingDays = 365 - holidays;

    totalMinutes = (workingDays * 63) + (holidays * 127);

    if (totalMinutes > norm)
    {
        difference = totalMinutes - norm;
        hours = difference / 60;
        minutes = difference % 60;

        cout << "Tom will not sleep well." << endl;
        cout << hours << " hours and " << minutes << " minutes more play time." << endl;
    }
    else
    {
        difference = norm - totalMinutes;
        hours = difference / 60;
        minutes = difference % 60;

        cout << "Tom sleeps well." << endl;
        cout << hours << " hours and " << minutes << " minutes less play time." << endl;
    }

    
}