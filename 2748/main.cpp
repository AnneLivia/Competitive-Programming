#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    string bet1,bet2;

    cin >> t;

    for ( int i = 1; i <= t; i++) {
        cin >> bet1 >> bet2;

        if(bet1.compare("tesoura") == 0 && bet2.compare("papel") == 0) {
            cout << "rajesh\n";
        } else if (bet1.compare("papel") == 0 && bet2.compare("tesoura") == 0) {
            cout << "sheldon\n";
        } else if(bet1.compare("papel") == 0 && bet2.compare("pedra") == 0) {
            cout << "rajesh\n";
        } else if (bet1.compare("pedra") == 0 && bet2.compare("papel") == 0) {
            cout << "sheldon\n";
        } else if(bet1.compare("pedra") == 0 && bet2.compare("lagarto") == 0) {
            cout << "rajesh\n";
        } else if (bet1.compare("lagarto") == 0 && bet2.compare("pedra") == 0) {
            cout << "sheldon\n";
        } else if(bet1.compare("lagarto") == 0 && bet2.compare("spock") == 0) {
            cout << "rajesh\n";
        } else if (bet1.compare("spock") == 0 && bet2.compare("lagarto") == 0) {
            cout << "sheldon\n";
        } else if(bet1.compare("spock") == 0 && bet2.compare("tesoura") == 0) {
            cout << "rajesh\n";
        } else if (bet1.compare("tesoura") == 0 && bet2.compare("spock") == 0) {
            cout << "sheldon\n";
        } else if(bet1.compare("tesoura") == 0 && bet2.compare("lagarto") == 0) {
            cout << "rajesh\n";
        } else if (bet1.compare("lagarto") == 0 && bet2.compare("tesoura") == 0) {
            cout << "sheldon\n";
        } else if(bet1.compare("lagarto") == 0 && bet2.compare("papel") == 0) {
            cout << "rajesh\n";
        } else if (bet1.compare("papel") == 0 && bet2.compare("lagarto") == 0) {
            cout << "sheldon\n";
        } else if(bet1.compare("papel") == 0 && bet2.compare("spock") == 0) {
            cout << "rajesh\n";
        } else if (bet1.compare("spock") == 0 && bet2.compare("papel") == 0) {
            cout << "sheldon\n";
        } else if(bet1.compare("spock") == 0 && bet2.compare("pedra") == 0) {
            cout << "rajesh\n";
        } else if (bet1.compare("pedra") == 0 && bet2.compare("spock") == 0) {
            cout << "sheldon\n";
        } else if(bet1.compare("pedra") == 0 && bet2.compare("tesoura") == 0) {
            cout << "rajesh\n";
        } else if (bet1.compare("tesoura") == 0 && bet2.compare("pedra") == 0) {
            cout << "sheldon\n";
        } else {
            cout << "empate\n";
        }
    }
    return 0;
}
