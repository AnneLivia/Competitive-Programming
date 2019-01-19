#include <iostream>
#define MAXN 100000

using namespace std;

int main()
{
    int n, i = 0, vet[MAXN], ma = -1, v;
    cin >> n;
    while(i < n) {
        cin >> v;
        vet[i++] = v;
    }

    for(int a = 0; a < n; a++) {
        for ( i = a; i < n; i++) {
            v = 0;
            for ( int j = a; j <= i; j++) {
                v |=vet[j];
            }

            if(v > ma)
                ma = v;
        }
    }

    cout << ma << endl;
    return 0;
}
