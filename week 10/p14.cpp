#include <iostream>
using namespace std;

float calculateSalary(float base, int score, int exp)
{
    float bonus = 0;

    if(score >= 90)
        bonus = 0.20;
    else if(score >= 75)
        bonus = 0.10;
    else
        bonus = 0.05;

    if(exp >= 5)
        bonus += 0.05;

    float finalSalary = base + (base * bonus);

    return finalSalary;
}

int main()
{
    cout << calculateSalary(50000, 92, 6);
    return 0;
}