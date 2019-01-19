#include <iostream>
#define MAXN 1000
using namespace std;

int main()
{
    string cos[MAXN], aux;
    int n, m, cont = 0;
    cin >> m >> n;
    cin.ignore();

    for ( int i = 0; i < m; i++) {
        getline(cin,aux);
        cos[i] = aux;
    }

    for ( int i = 0; i < m; i++) {
        for ( int j = 0; j < n; j++) {
            if(cos[i][j] == '#') {
                if(i != 0 && i != m - 1 && j != n - 1 && j != 0) {
                    if(cos[i - 1][j] != '#' || cos[i][j + 1] != '#' || cos[i][j - 1] != '#' || cos[i + 1][j] != '#') {
                        cont++;
                    }
                } else if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
                    cont++;
            }
        }
    }

    cout << cont << endl;
    return 0;
}
