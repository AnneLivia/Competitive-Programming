#include <iostream>
#include <string>

using namespace std;

int main()
{
    int abI, qtdAct, qtdAA = 0;
    string act;
    cin >> abI >> qtdAct;
    while(qtdAct--) {
        cin >> act;
        if(act.compare("fechou") == 0) {
            qtdAA = (abI - 1) + 2;
            abI = qtdAA;
        } else {
            abI--;
        }
    }
    cout << abI << endl;
    return 0;
}
