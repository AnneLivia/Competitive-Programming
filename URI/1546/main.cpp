#include <iostream>

using namespace std;

int main()
{
    int cTeste, k, teste;
    cin >> cTeste;
    while(cTeste--) {
        cin >> k;
        while(k--) {
            cin >> teste;
            switch(teste) {
                case 1: cout << "Rolien\n"; break;
                case 2: cout << "Naej\n"; break;
                case 3: cout << "Elehcim\n"; break;
                case 4: cout << "Odranoel\n";break;
            }
        }
    }
    return 0;
}
