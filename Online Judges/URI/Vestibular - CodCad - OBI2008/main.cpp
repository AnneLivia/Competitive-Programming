#include <iostream>

using namespace std;

int main()
{
    int qtdQuestion, cont = 0;
    string gabarito, ans;

    cin >> qtdQuestion;
    cin >> gabarito;
    cin >> ans;
    for(int i = 0; i < qtdQuestion; i++) {
        if(gabarito[i] == ans[i])
            cont++;
    }

    cout <<  cont << endl;
    return 0;
}
