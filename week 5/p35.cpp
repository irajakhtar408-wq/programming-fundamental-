#include <iostream>
using namespace std;

 main() 
 {
    int num = 1; 

    
    for (int i = 1; i <= 5; i++)
     {   
        for (int j = 1; j <= i; j++) 
        {
            cout << num << " ";  
            num++;               
        }
        cout << endl;  
    }

    return 0;
}