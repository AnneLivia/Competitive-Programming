#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double al, ga, gal, gga;
    cin >> al >> ga >> gal >> gga;
    if(al / gal < ga / gga)
        cout << "A\n";
    else
        cout << "G\n";
    return 0;
}
