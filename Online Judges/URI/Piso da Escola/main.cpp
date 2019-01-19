#include <iostream>

using namespace std;

int main()
{
    int l, c;
    cin >> c >> l;
    cout << l * c + ((l - 1) * (c - 1)) << endl;
    cout << 2 * ((l - 1) + (c - 1)) << endl;
    return 0;
}
