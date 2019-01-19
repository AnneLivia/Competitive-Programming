#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<char> partidas;
    char team1 = 'A', team2;
    int gols1, gols2, cont = 0;
    while(cont < 16) {
        // Colocando todas as letras representantes dos times
        partidas.push(team1++);
        cont++;
    }
    cont = 0;
    while(cont < 15) {
        cin >> gols1 >> gols2;
        if(gols1 > gols2) {
            team1 = partidas.front(); // Pegando o primeiro time
            partidas.pop();
            partidas.pop();
            partidas.push(team1); // Adicionando ele para o fim da fila
        } else {
            partidas.pop();
            team2 = partidas.front(); // Pegando o segundo time
            partidas.pop();
            partidas.push(team2); // Adicionando ele para o fim da fila
        }
        cont++;
    }

    while(!partidas.empty()) {
        cout << partidas.front() << endl;
        partidas.pop();
    }

    return 0;
}
