#include <iostream>
using namespace std;
int main()
 {
    int squaremeter; 
    int width, height; 
    int wall_area, complete_walls;

   
    cout << "Enter total paint square meter: ";
    cin >> squaremeter;
    cout << "Enter wall width : ";
    cin >> width;
    cout << "Enter wall height : ";
    cin >> height;

    
    wall_area = width * height;

    complete_walls = squaremeter/ wall_area;
cout<<" total number of wall :"<<complete_walls;
}