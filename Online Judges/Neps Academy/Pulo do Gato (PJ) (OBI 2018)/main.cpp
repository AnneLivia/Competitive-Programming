#include <iostream>

using namespace std;

int main()
{
    int t, v[10001], p = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> v[i];
    }

    int i = 0;
    for (; i < t ;) {
        if (i + 2 < t && v[i + 2] == 1) {
            p++;
            i+=2;
        } else if (i + 1 < t && v[i + 1] == 1) {
            p++;
            i+=1;
        } else {
            break;
        }
    }

    if (t == i+1) {
        cout << p << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}
