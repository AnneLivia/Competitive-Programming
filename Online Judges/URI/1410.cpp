#include <iostream>
#include <algorithm>

using namespace std;

/*
    Problema: Ele Est� Impedido! - 1410.

    Um jogador atacante est� impedido se ele est� mais pr�ximo da linha do gol do oponente do que o pen�ltimo advers�rio. Um jogador n�o est� impedido se

    - ele est� na mesma linha que o pen�ltimo advers�rio ou
    - ele est� na mesma linha que os dois �ltimos advers�rios.
*/

void sortt(int *df, int n) {
     for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (df[i] > df[j]) {
                int aux = df[i];
                df[i] = df[j];
                df[j] = aux;
            }
        }
    }
}

int main() {

    int a, d, df[11], af[11], ok;

    while (cin >> a >> d && a && d) {
        ok = 1;
        // Reading Attackers
        for (int i = 0; i < a; i++)
            cin >> af[i];

        // Reading Defenders
        for (int i = 0; i < d; i++)
            cin >> df[i];



        sortt(df, d);

        // checking if there's no player in the wrong position
        for (int i = 0; i < a; i++) {
            // for each player, check if it's not in a correct position
            for (int j = 0; j < 2; j++) {
                if (af[i] < df[j]) {
                    ok = 0;
                }
            }
        }

        ok ? cout << "N" << endl : cout << "Y" << endl;

    }

    return 0;
}
