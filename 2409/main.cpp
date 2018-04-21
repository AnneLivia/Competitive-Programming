#include <iostream>

using namespace std;

int main()
{
    int a, b, c, l, h;
    cin >> a >> b >> c >> l >> h;
    if(a <= l && b <= h) {
        cout << "S\n";
    } else if (a <= l && c <= h) {
        cout << "S\n";
    } else if (b <= l && a <= h) {
        cout << "S\n";
    } else if (b <= l && c <= h) {
        cout << "S\n";
    } else if (c <= l && a <= h) {
        cout << "S\n";
    } else if (c <= l && b <= h) {
        cout << "S\n";
    } else {
        cout << "N\n";
    }
    return 0;
}
