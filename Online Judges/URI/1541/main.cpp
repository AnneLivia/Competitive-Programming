#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a;
    double b, c;

    while(cin >> a && a) {
        cin >> b >> c ;
        cout << trunc(sqrt((a*b*100/c))) << endl;
    }
    return 0;
}
