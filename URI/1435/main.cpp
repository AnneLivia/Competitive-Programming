#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

int main()
{
    int tam, arrays[100][100];
    int a = 0, b, n, s;


    while(true) {
        cin >> tam;
        if(tam == 0)
            break;

        /* In this line I'm inserting the number 1 on the edges of the array */
        for ( int i = 0; i < tam; i++) {
            for ( int j = 0; j < tam; j++) {
                if(i != 0 && j != 0 && i != (tam - 1) && j != (tam - 1))
                    arrays[i][j] = 0;
                else
                    arrays[i][j] = 1;
            }
        }
        n = 2;
        a = 1;
        b = tam - n;
        int pos;
        for ( int i = a; i <= tam/2; i++) {
            for ( int j = i; j <= b; j++) {
                arrays[i][j] = n;
            }
            n++;
            a++;
            b--;
            pos = i;
        }
        if(tam % 2 == 0) {
            s = pos;
            b = (tam - b) - 1;
        } else {
            s = pos + 1;
            b = (tam - b);
        }
        a = a - 2;


        n-=2;

        for ( int i = s; i < tam - 1; i++) {
            for ( int j = a; j < b; j++) {
                    arrays[i][j] = n;
            }
            n--;
            a--;
            b++;
        }

        for ( int i = 2; i < tam; i++) {
            for ( int j = 1; j < tam; j++) {
                if(arrays[i][j] == 0)
                    arrays[i][j] = arrays[i-1][j];
            }
        }

        for ( int i = 0; i < tam; i++) {
            for ( int j = 0; j < tam; j++) {
                cout << right << setw(3) << arrays[i][j];
                if(j < tam - 1)
                    cout << " ";
            }
            cout << endl;
        }

        cout << endl;
    }
    return 0;

}
