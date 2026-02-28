#include<iostream>
using namespace std;
main()
{
cout<<" enter imposter :";
int imposter;
cin>> imposter;

cout<<"enter player count :";
int player;
cin>> player;

int chance;
chance = 100*(imposter/player);
cout<<" your chance of being an imposter is :" << chance;
}