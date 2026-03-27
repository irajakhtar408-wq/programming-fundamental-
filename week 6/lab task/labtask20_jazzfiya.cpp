#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> addSevenToChords(const vector<string> &chords) 
{
    vector<string> result;
    for (string chord : chords)
     {
        
        if (!chord.empty() && chord.back() == '7') 
        {
            result.push_back(chord); 
        } else 
        {
            result.push_back(chord + "7"); 
        }
    }
    return result;
}

int main()
 {
    int n;
    cout << "Enter number of chords: ";
    cin >> n;

    vector<string> chords(n);
    cout << "Enter " << n << " chords:" << endl;
    for (int i = 0; i < n; i++) 
    {
        cin >> chords[i];
    }

    vector<string> updated = addSevenToChords(chords);

    cout << "Updated chords:" << endl;
    for (string chord : updated) 
    {
        cout << chord << " ";
    }
    cout << endl;

    return 0;
}