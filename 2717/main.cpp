#include <iostream>

using namespace std;

int main()
{
    int fTempo, tempoA, tempoB;
    cin >> fTempo;
    cin >> tempoA >> tempoB;
    if(tempoA + tempoB <= fTempo)
        cout << "Farei hoje!\n";
    else
        cout << "Deixa para amanha!\n";
    return 0;
}
