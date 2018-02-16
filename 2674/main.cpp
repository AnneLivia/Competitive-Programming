#include <iostream>
#include <stack>

using namespace std;

bool eh_primo(int n);

int main()
{
    long long unsigned int n, aux;
    int contNP, contN;
    while(cin >> n) {
        aux = n;
        contNP = contN = 0;
        stack <bool> nPrimos;

        if(eh_primo(n)) {
            while(n > 0) {
                aux = n % 10;
                if(eh_primo(aux))
                    nPrimos.push(true);
                else
                    nPrimos.push(false);
                n /=10;
                contN++;
            }

            while(!nPrimos.empty()) {
                if(nPrimos.top())
                    contNP++;
                nPrimos.pop();
            }

            if(contN == contNP)
                cout << "Super\n";
            else
                cout << "Primo\n";
        } else {
            cout << "Nada\n";
        }

    }
    return 0;
}
// O(sqrt(n))
bool eh_primo(int n) {
    if(n == 1 || n == 0)
        return false;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0)
            return false;
    }
    return true;
}
