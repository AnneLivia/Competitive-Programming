#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int m[15][15], n, maior, dig, cont;

    while(true) {
        cin >> n;
        if(n == 0)
            break;
        int num = 1;
        m[0][0] = 1;
        maior = m[0][0];
        for ( int i = 0; i < n; i++) {
            m[i][0] = num;
            for ( int j = 1; j < n; j++) {
                m[i][j] = m[i][j-1] * 2;
                if(maior < m[i][j])
                    maior = m[i][j];
            }
            num *= 2;
        }

        cont = 0;
        dig = maior;
        while(true) {
            maior = maior / 10;
            cont++;
            if(maior == 0)
                break;
        }

        for ( int i = 0; i < n; i++) {
            for ( int j = 0; j < n; j++) {
                cout << right << setw(cont) << m[i][j];
                if(j < n - 1)
                    cout << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}
