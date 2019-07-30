#include <iostream>

using namespace std;

int main()
{
    int h, p, f, d;

    cin >> h >> p >> f >> d;

    while(f != p && f!= h) {
        if(d == 1) {
            f++;
            if(f == 16)
                f = 0;
        } else {
            f--;
            if(f == -1) {
                f = 15;
            }
        }
    }

    if(f == h) {
        cout << "S\n";
    } else {
        cout << "N\n";
    }
    return 0;
}
