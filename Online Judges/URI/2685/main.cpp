#include <iostream>

using namespace std;

int main()
{
    int grau;
    while(cin >> grau) {
        if(grau == 360) {
            cout << "Bom dia!!\n";
        }
        if(grau >= 0 && grau < 90) {
            cout << "Bom dia!!\n";
        } else if (grau >= 90 && grau < 180) {
            cout << "Boa Tarde!!\n";
        } else if (grau >= 180 && grau < 270) {
            cout << "Boa noite!!\n";
        } else if (grau >= 270 && grau < 360) {
            cout << "De Madrugada!!\n";
        }
    }
    return 0;
}
