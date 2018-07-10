#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n, mat[71][71];

    while(cin >> n) {
        for ( int i = 0; i < n; i++) {
            for ( int j = 0; j < n; j++) {
                mat[i][j] = 3;
            }
        }

        for ( int i = 0; i < n; i++) {
            mat[i][i] = 1;
        }
        int j = 0;
        for ( int i = n - 1; i >= 0; i--) {
            mat[j++][i] = 2;
        }

        for ( int i = 0; i < n; i++) {
            for ( int j = 0; j < n; j++) {
                cout << mat[i][j];
            }
            cout << endl;
        }

    }
    return 0;
}
