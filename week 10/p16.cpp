#include <iostream>
using namespace std;

float calculateBalance(float balance, int years)
{
    float rate;

    if(balance < 10000)
        rate = 0.05;
    else if(balance <= 50000)
        rate = 0.07;
    else
        rate = 0.10;

    if(years >= 3)
        rate += 0.02;

    float finalBalance = balance + (balance * rate);

    return finalBalance;
}

int main()
{
    cout << calculateBalance(20000, 4);
    return 0;
}