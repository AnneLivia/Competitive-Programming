#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main()
{
    vector<vector<char>>mat;
    vector<char>aux;
    int n;
    while(cin >> n) {
        aux.assign(n,'0');
        mat.assign(n,aux);

        for(int i = 0; i < n; i++)
            mat[i][i] = '2';
        int j = n - 1;
        for(int i = 0; i < n; i++)
            mat[i][j--] = '3';

        for ( int i = n/3; i < n - n/3; i++) {
            for ( int j = n/3; j < n - n/3; j++) {
                mat[i][j] = '1';
            }
        }

        mat[n/2][n/2] = '4';

        for ( int i = 0; i < n; i++) {
            for ( int j = 0; j < n; j++) {
                cout << mat[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
