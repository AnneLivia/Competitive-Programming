#include <iostream>
#include <stack>

using namespace std;

int main()
{
    long long unsigned int dec;
    int qtTeste, cont, maior;
    cin >> qtTeste;

    while(qtTeste--) {
        cin >> dec;
        stack <int> nBin;
        nBin.push(0); // To make it works, putting a 0 "at the end" of the binary number
        do{
            nBin.push(dec % 2);
            dec /=2;

        }while(dec > 0);
        cont = 0, maior = 0;
        while(!nBin.empty()) {
            if(nBin.top() == 1) {
                cont++;
            } else {
                if(cont > maior) {
                    maior = cont;
                }
                cont = 0;
            }
            nBin.pop();
        }

        cout << maior << endl;
    }

    return 0;
}
