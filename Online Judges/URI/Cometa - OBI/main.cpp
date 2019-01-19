#include <iostream>

using namespace std;

int main()
{
    int a, r;
    cin >> a;
    for ( int i = 1986;;i+=76) {
        if(i > a) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
