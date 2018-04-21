#include <iostream>

using namespace std;

int main()
{
    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    int area1 = a * b + c * d;
    int area2 = e * f;
    if(area1 >= area2) {
        cout << "S\n";
    } else {
        cout << "N\n";
    }
    return 0;
}
