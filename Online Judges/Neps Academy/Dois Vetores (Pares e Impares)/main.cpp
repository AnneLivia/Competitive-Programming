#include <iostream>

using namespace std;

int main()
{
    int p[10], im[10];

    int t, a = 0, b = 0;
    for (int i = 0; i < 10; i++) {
        cin >> t;
        if ((t & 1) == 0) {
            p[a++]=t;
        } else {
            im[b++]=t;
        }
    }

    for (int i = 0; i < a; i++) {
        cout << p[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < b; i++) {
        cout << im[i] << " ";
    }

    cout << endl;

    return 0;
}
