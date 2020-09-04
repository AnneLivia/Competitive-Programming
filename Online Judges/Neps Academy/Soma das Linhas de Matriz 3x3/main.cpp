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

    for (int i = 0; i < 3; i++) {
        cout << "Linha " << i << ": ";
        int sum = 0;
        for (int j = 0; j < 3; j++) {
            sum+=a[i][j];
        }
        cout << sum << endl;
    }
    return 0;
}
