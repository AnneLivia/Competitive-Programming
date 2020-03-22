#include <iostream>

using namespace std;

int main()
{
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;

    if ((x1 <= (n/2) && x2 > (n/2)) ||
        (x1 < (n/2) && x2 >= (n/2)) ||
        (x2 <= (n/2) && x1 > (n/2)) ||
        (x2 < (n/2) && x2 >= (n/2))) {
        cout << "S\n";
    } else {
        if ((y1 <= (n/2) && y2 > (n/2)) ||
        (y1 < (n/2) && y2 >= (n/2)) ||
        (y2 <= (n/2) && y1 > (n/2)) ||
        (y2 < (n/2) && y2 >= (n/2))) {
            cout << "S\n";
        } else {
            cout << "N\n";
        }
    }
    return 0;
}
