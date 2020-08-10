#include <iostream>

using namespace std;

int main()
{
    int a[3][3], mm = -0x3f3f3f3f;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
            if (a[i][j] > mm) {
                mm = a[i][j];
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[i][j] == mm)
                a[i][j] = -1;
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
