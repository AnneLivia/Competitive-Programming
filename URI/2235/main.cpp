#include <iostream>

using namespace std;

int main()
{
    int t1, t2, t3;
    cin >> t1 >> t2 >> t3;
    if(t1 == t2)
        cout << "S\n";
    else if (t1 == t3) {
        cout << "S\n";
    } else if (t2 == t3) {
        cout << "S\n";
    } else if (t1 + t2 == t3) {
        cout << "S\n";
    } else if (t1 + t3 == t2) {
        cout << "S\n";
    } else if (t2 + t3 == t1) {
        cout << "S\n";
    } else {
        cout << "N\n";
    }
    return 0;
}
