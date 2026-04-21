#include <iostream>
using namespace std;

string projectTimeCalculation(int neededHours, int days, int workers)
{
    int trainingDays = days * 0.10;
    int workingDays = days - trainingDays;

    int totalHours = workingDays * workers * 10; // 8 + 2 overtime

    if(totalHours >= neededHours)
    {
        int left = totalHours - neededHours;
        return "Yes! " + to_string(left) + " hours left.";
    }
    else
    {
        int need = neededHours - totalHours;
        return "Not enough time! " + to_string(need) + " hours needed.";
    }
}

int main()
{
    int h, d, w;

    cin >> h >> d >> w;

    cout << projectTimeCalculation(h,d,w);

    return 0;
}