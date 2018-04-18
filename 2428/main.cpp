#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a1, a2, a3, a4;
    cin >> a1 >> a2 >> a3 >> a4;
    // Verify if at least two sides are equal, then it forms an rectangle
    if(a1*a2 == a3*a4)
        cout << "S\n";
    else if (a1 * a3 == a2 * a4)
        cout << "S\n";
    else if (a1 * a4 == a2 * a3)
        cout << "S\n";
    else
        cout << "N\n";
    return 0;
}
