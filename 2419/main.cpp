#include <iostream>
#include <vector>

using namespace std;

char vet[1000][1000] = {'.'};


int main()
{
    int n, m, cont = 0;
    char c;

    cin >> n >> m;

    for ( int i = 0; i < n; i++) {
        for ( int j = 0; j < m; j++) {
            cin >> c;
            vet[i][j] = c;
        }
    }

    for ( int i = 0; i < n; i++) {
        for ( int j = 0; j < m; j++) {
            if(vet[i][j] == '#') {
                if( i == 0 || j == 0 || i == n - 1 || j == m - 1 ||
                    i - 1 >= 0 && vet[i - 1][j] == '.' ||
                    i + 1 < n && vet[i + 1][j] == '.' ||
                    j - 1 >= 0 && vet[i][j - 1] == '.' ||
                    j + 1 < m && vet[i][j + 1] == '.')
                        cont++;
            }
        }
    }

    cout << cont << endl;

    return 0;
}
