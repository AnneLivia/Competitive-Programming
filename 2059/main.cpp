#include <iostream>

using namespace std;

int main()
{
    int j1, j2, p, r, a;

    cin >> p; // 1 - even, 0 - odd
    cin >> j1 >> j2; // Number from player 1 and player 2
    cin >> r; // 1 - player 1 cheated, 0 - player 1 hasn't cheated
    cin >> a; // 1 - player 2 has accused him, 0 - player 2 hasn't accused him

    if(r == 1) {
        if(a == 1) {
            cout << "Jogador 2 ganha!\n";
        } else {
            cout << "Jogador 1 ganha!\n";
        }
    } else {
        if(a == 1) {
            cout << "Jogador 1 ganha!\n";
        } else {
            if((j1 + j2) % 2 == 0 && p == 1)
                cout << "Jogador 1 ganha!\n";
            else if (p == 0 && (j1 + j2) % 2 != 0)
                cout << "Jogador 1 ganha!\n";
            else
                cout << "Jogador 2 ganha!\n";
        }
    }
    return 0;
}
