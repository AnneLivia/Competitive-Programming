#include <iostream>

using namespace std;

int findminus1(int n, int vet[]) {
    for ( int i = 0; i < n; i++) {
        if(vet[i] == -1)
            return 1;
    }
    return 0;
}
int main()
{
    int n, b, vet[100], numb[91], notf;

    while(cin >> n >> b) {
        if(n == 0 && b == 0)
            break;
        notf = 1;
        n++;
        for ( int i = 0; i < n; i++) {
            numb[i] = -1;
        }

        for ( int i = 0; i < b; i++) {
            cin >> vet[i];
        }

        // FIX IT LATER
        while(findminus1(n,numb) && notf) {
            for ( int i = 0; i < b; i++) {
                for ( int j = 0; j < b; j++) {
                    int p = abs(vet[i] - vet[j]);
                    numb[p]++;
                }
            }
            notf = 0;
        }

        if(!findminus1(n,numb))
            cout << "Y\n";
        else
            cout << "N\n";
    }
    return 0;
}
