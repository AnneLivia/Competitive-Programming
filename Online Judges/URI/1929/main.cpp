#include <iostream>

using namespace std;

int main()
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a + b > c && a + c > b && b + c > a) {
        cout << "S" << endl;
    } else if (a + b > d && a + d > b && b + d > a) {
        cout << "S" << endl;
    }  else if (d + b > c && d + c > b && b + c > d) {
        cout << "S" << endl;
    } else if (d + a > c && d + c > a && a + c > d) {
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }

    return 0;
}
