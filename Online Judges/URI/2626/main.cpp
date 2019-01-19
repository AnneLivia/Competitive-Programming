#include <iostream>

using namespace std;

int main()
{
    string j1, j2, j3;
    while(cin >> j1 >> j2 >> j3) {
        if(j1 == "papel" && j2 == "pedra" && j3 == "pedra" ||
           j1 == "pedra" && j2 == "tesoura" && j3 == "tesoura" ||
           j1 == "tesoura" && j2 == "papel" && j3 == "papel") {

            cout << "Os atributos dos monstros vao ser inteligencia, sabedoria...\n";

        } else if (j2 == "papel" && j1 == "pedra" && j3 == "pedra" ||
                   j2 == "pedra" && j1 == "tesoura" && j3 == "tesoura" ||
                   j2 == "tesoura" && j1 == "papel" && j3 == "papel") {

            cout << "Iron Maiden's gonna get you, no matter how far!\n";

        } else if (j3 == "papel" && j1 == "pedra" && j2 == "pedra" ||
                   j3 == "pedra" && j1 == "tesoura" && j2 == "tesoura" ||
                   j3 == "tesoura" && j1 == "papel" && j2 == "papel") {

            cout << "Urano perdeu algo muito precioso...\n";
        } else {
            cout << "Putz vei, o Leo ta demorando muito pra jogar...\n";
        }
    }
    return 0;
}
