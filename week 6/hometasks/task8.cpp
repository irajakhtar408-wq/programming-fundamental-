#include <iostream>
using namespace std;

struct Flight 
{
    int flightNumber;
    string destination;
    int seats;
};

int main() 
{
    int n;
    cout << "Enter number of flights: ";
    cin >> n;
    cin.ignore(); 

    Flight flights[n];

    
    for (int i = 0; i < n; i++) 
    {
        cout << "\nEnter flight number for flight " << (i + 1) << ": ";
        cin >> flights[i].flightNumber;
        cin.ignore();

        cout << "Enter destination for flight " << flights[i].flightNumber << ": ";
        getline(cin, flights[i].destination);

        cout << "Enter seats available for flight " << flights[i].flightNumber << ": ";
        cin >> flights[i].seats;
        cin.ignore();
    }

    
    cout << "\nFlight Information:\n";
    cout << "-------------------\n";
    for (int i = 0; i < n; i++) 
    {
        cout << "Flight " << flights[i].flightNumber << " to " 
             << flights[i].destination << " has " 
             << flights[i].seats << " seats available." << endl;
    }

    
    cout << "\nFlights with less than 5 seats available:\n";
    cout << "-----------------------------------------\n";
    bool found = false;
    for (int i = 0; i < n; i++) 
    {
        if (flights[i].seats < 5) 
        {
            cout << "Flight " << flights[i].flightNumber << " to " 
                 << flights[i].destination << " has only " 
                 << flights[i].seats << " seats left!" << endl;
            found = true;
        }
    }
    if (!found) 
    {
        cout << "No flights with less than 5 seats available." << endl;
    }

    return 0;
}