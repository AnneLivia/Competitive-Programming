#include <iostream>

using namespace std;

int main()
{
    int c, a, v = 0;
    cin >> c >> a;

    while(a > 0) {
        a-=(c - 1);
        v++;
    }
    cout << v << endl;
    return 0;
}
