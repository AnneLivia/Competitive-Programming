#include <iostream>

using namespace std;

int main()
{
    int t, qtdAli, soma;
    string ali;

    while(cin >> t && t) {
        soma = 0;
        while(t--) {
            cin >> qtdAli;
            cin.ignore();
            getline(cin,ali);
            if(ali.compare("suco de laranja") == 0) {
                soma+=(qtdAli * 120);
            } else if (ali.compare("morango fresco") == 0) {
                soma+=(qtdAli * 85);
            } else if (ali.compare("mamao") == 0) {
                soma+=(qtdAli * 85);
            } else if (ali.compare("goiaba vermelha") == 0) {
                soma+=(qtdAli * 70);
            } else if (ali.compare("manga") == 0) {
                soma+=(qtdAli * 56);
            } else if (ali.compare("laranja") == 0) {
                soma+=(qtdAli * 50);
            } else if (ali.compare("brocolis") == 0) {
                soma+=(qtdAli * 34);
            }
        }

        if(soma >= 110 && soma <= 130) {
            cout << soma << " mg\n";
        } else if (soma > 130) {
            cout << "Menos " << soma - 130 << " mg" << endl;
        } else {
            cout << "Mais " << 110 - soma << " mg" << endl;
        }
    }
    return 0;
}
