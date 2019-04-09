#include <iostream>

using namespace std;

int main()
{
    int atraso[2], reacao[2], escrita[2], re[2];
    string text;
    for (int i = 0; i < 2; i++) {
        cin >> atraso[i] >> reacao[i] >> escrita[i];
    }
    cin.ignore();
    getline(cin, text);
    for (int i = 0; i < 2; i++)
        re[i] = (2*atraso[i]) + reacao[i] + (escrita[i] * (int)text.size());
    if(re[0] < re[1])
        cout << "Matheus\n";
    else if(re[0] > re[1]) {
        cout << "Vinicius\n";
    } else {
        cout << "Empate\n";
    }
    return 0;
}
