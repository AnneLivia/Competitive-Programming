#include <iostream>

using namespace std;

void traco() {
    for ( int i = 0; i < 39; i++) {
        cout << "-";
    }
}

void barra() {
    for ( int i = 0; i < 39; i++) {
        if(i == 0 || i == 38)
            cout << "|";
        else
            cout << " ";
    }
}
int main()
{

    traco();
    cout << endl;
    barra();
    cout << endl;
    barra();
    cout << endl;
    barra();
    cout << endl;
    barra();
    cout << endl;
    barra();
    cout << endl;
    traco();
    cout << endl;
    return 0;
}
