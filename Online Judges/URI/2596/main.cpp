#include <iostream>

using namespace std;

int main()
{
    int c, n, cont, total;
    cin >> c;
    while(c--) {
        total = 0;
        cin >> n;
        for ( int i = 1; i <= n; i++) {
            cont = 0;
            for(int j = 1; j <= i; j++) {
                if(i % j == 0)
                    cont++;
            }
            if(cont % 2 == 0)
                total++;
        }
        cout << total << endl;
    }
    return 0;
}
