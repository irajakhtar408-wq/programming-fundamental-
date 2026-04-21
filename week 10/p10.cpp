#include <iostream>
using namespace std;

string timeTravel(int h, int m)
{
    m += 15;

    if(m >= 60)
    {
        h += 1;
        m -= 60;
    }

    if(h == 24)
        h = 0;

    return to_string(h) + ":" + to_string(m);
}

int main()
{
    int h, m;

    cout << "Enter hours and minutes: ";
    cin >> h >> m;

    cout << timeTravel(h, m);

    return 0;
}