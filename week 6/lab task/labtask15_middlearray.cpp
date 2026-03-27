#include <iostream>
using namespace std;


void insertArray(int a[], int b[], int c[]);

int main()
{
    int a[2], b[50], c[100];
    int n;

    cout << "Enter 2 elements of first array: ";
    for(int i = 0; i < 2; i++)
    {
        cin >> a[i];
    }

    cout << "Enter size of second array: ";
    cin >> n;

    cout << "Enter elements of second array: ";
    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    insertArray(a, b, c);

    return 0;
}

void insertArray(int a[], int b[], int c[])
{
    int i = 0, j = 0;

    
    c[i++] = a[0];
    c[i++] = a[1];

    
    while(b[j] != '\0')
    {
        c[i++] = b[j++];
    }

    
    cout << "New array: ";
    for(int k = 0; k < i; k++)
    {
        cout << c[k] << " ";
    }
}