#include <iostream>

using namespace std;

int main()
{
    int n1, n2, ok, vet[6] = {2,5,10,20,50,100};
    while(cin >> n1 >> n2 && n1 && n2) {
        ok = 0;
        for ( int i = 0; i < 6; i++) {
            for ( int j = 0; j < 6; j++) {
                if(vet[i] + vet[j] == (n2 - n1)) {
                    ok = 1;
                    break;
                }
            }
        }
        if(ok)
            cout << "possible\n";
        else
            cout << "impossible\n";
    }
    return 0;
}
