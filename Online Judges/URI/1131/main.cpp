#include <iostream>

using namespace std;

int main()
{
    int n1, n2, gremio, inter, contGame, opt, emp;
    gremio = inter = contGame = emp = 0;

    do {
        contGame++;
        cin >> n1 >> n2;
        if(n1 > n2)
            inter++;
        else if(n1 < n2)
            gremio++;
        else
            emp++;
        cout << "Novo grenal (1-sim 2-nao)\n";
        cin >> opt;
    } while (opt == 1);
    cout << contGame << " grenais\n";
    cout << "Inter:" << inter << endl;
    cout << "Gremio:" << gremio << endl;
    cout << "Empates:" << emp << endl;
    if(inter > gremio)
        cout << "Inter venceu mais\n";
    else if(gremio > inter)
        cout << "Gremio venceu mais\n";
    else
        cout << "Nao houve vencedor\n";
    return 0;
}
