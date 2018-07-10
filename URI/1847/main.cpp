#include <iostream>

using namespace std;

int main()
{
    int n1, n2, n3;

    cin >> n1 >> n2 >> n3;

    if(n2 < n1 && n3 >= n2) {
        cout << ":)" << endl;
    } else if (n2 > n1 && n3 <= n2) {
        cout << ":(" << endl;
    } else if (n2 > n1 && n3 > n2 && (n2 - n1) > (n3 - n2)) {
        cout << ":(" << endl;
    } else if (n2 > n1 && n3 > n2 && (n3 - n2) >= (n2 - n1)) {
        cout << ":)" << endl;
    } else if (n2 < n1 && n3 < n2 && (n3 - n2) > (n2 - n1)) {
        cout << ":)" << endl;
    } else if (n2 < n1 && n3 < n2 && (n3 - n2) >= (n2 - n1)) {
        cout << ":(" << endl;
    } else if(n1 == n2 && n3 > n2) {
        cout << ":)" << endl;
    } else {
        cout << ":(" << endl;
    }

    return 0;
}
