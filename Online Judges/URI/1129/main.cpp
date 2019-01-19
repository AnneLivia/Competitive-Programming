#include <iostream>

using namespace std;

int main()
{
    int n, vet[5], r, qtb;
    char l[5] = {'A','B','C','D','E'};
    while(cin >> n && n) {
        while(n--) {
            qtb = r = 0;
            for(int i = 0; i < 5; i++)
                cin >> vet[i];

            for(int i = 0; i < 5; i++) {
                if(vet[i] <= 127) {
                    qtb++;
                    r = i;
                }
            }

            if(qtb == 1) {
                cout << l[r] << endl;
            } else {
                cout << "*\n";
            }
        }
    }
    return 0;
}
