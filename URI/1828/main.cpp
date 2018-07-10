#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    string bet1,bet2;

    do {
        cin >> t;
    } while(t < 0 || t > 100);

    for ( int i = 1; i <= t; i++) {
        cin >> bet1 >> bet2;

        if(bet1.compare("tesoura") == 0 && bet2.compare("papel") == 0) {
            cout << "Caso #"<<i << ": Bazinga!";
        } else if (bet1.compare("papel") == 0 && bet2.compare("tesoura") == 0) {
            cout << "Caso #"<<i << ": Raj trapaceou!";
        } else if(bet1.compare("papel") == 0 && bet2.compare("pedra") == 0) {
            cout << "Caso #"<<i << ": Bazinga!";
        } else if (bet1.compare("pedra") == 0 && bet2.compare("papel") == 0) {
            cout << "Caso #"<<i << ": Raj trapaceou!";
        } else if(bet1.compare("pedra") == 0 && bet2.compare("lagarto") == 0) {
            cout << "Caso #"<<i << ": Bazinga!";
        } else if (bet1.compare("lagarto") == 0 && bet2.compare("pedra") == 0) {
            cout << "Caso #"<<i << ": Raj trapaceou!";
        } else if(bet1.compare("lagarto") == 0 && bet2.compare("Spock") == 0) {
            cout << "Caso #"<<i << ": Bazinga!";
        } else if (bet1.compare("Spock") == 0 && bet2.compare("lagarto") == 0) {
            cout << "Caso #"<<i << ": Raj trapaceou!";
        } else if(bet1.compare("Spock") == 0 && bet2.compare("tesoura") == 0) {
            cout << "Caso #"<<i << ": Bazinga!";
        } else if (bet1.compare("tesoura") == 0 && bet2.compare("Spock") == 0) {
            cout << "Caso #"<<i << ": Raj trapaceou!";
        } else if(bet1.compare("tesoura") == 0 && bet2.compare("lagarto") == 0) {
            cout << "Caso #"<<i << ": Bazinga!";
        } else if (bet1.compare("lagarto") == 0 && bet2.compare("tesoura") == 0) {
            cout << "Caso #"<<i << ": Raj trapaceou!";
        } else if(bet1.compare("lagarto") == 0 && bet2.compare("papel") == 0) {
            cout << "Caso #"<<i << ": Bazinga!";
        } else if (bet1.compare("papel") == 0 && bet2.compare("lagarto") == 0) {
            cout << "Caso #"<<i << ": Raj trapaceou!";
        } else if(bet1.compare("papel") == 0 && bet2.compare("Spock") == 0) {
            cout << "Caso #"<<i << ": Bazinga!";
        } else if (bet1.compare("Spock") == 0 && bet2.compare("papel") == 0) {
            cout << "Caso #"<<i << ": Raj trapaceou!";
        } else if(bet1.compare("Spock") == 0 && bet2.compare("pedra") == 0) {
            cout << "Caso #"<<i << ": Bazinga!";
        } else if (bet1.compare("pedra") == 0 && bet2.compare("Spock") == 0) {
            cout << "Caso #"<<i << ": Raj trapaceou!";
        } else if(bet1.compare("pedra") == 0 && bet2.compare("tesoura") == 0) {
            cout << "Caso #"<<i << ": Bazinga!";
        } else if (bet1.compare("tesoura") == 0 && bet2.compare("pedra") == 0) {
            cout << "Caso #"<<i << ": Raj trapaceou!";
        } else {
            cout << "Caso #"<< i << ": De novo!";
        }
        cout << endl;
    }
    return 0;
}
