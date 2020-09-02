#include <iostream>

using namespace std;

int main()
{
    int a[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }

    cout << "Diagonal principal: ";
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        sum+=a[i][i];
    }
    cout << sum << endl;

    cout << "Diagonal secundaria: ";
    sum = 0;
    for (int i = 0, j = 2; i < 3; i++, j--) {
        sum+=a[i][j];
    }
    cout << sum << endl;
    return 0;
}
