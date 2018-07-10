#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    int valor, notas[7] = {0};
    do{
        cin >> valor;
    }while(valor <= 0 && valor >= 1000000);
	cout << valor << endl;
	while(valor >= 100) {
        notas[0] = notas[0] + 1;
        valor -=100;
	}
    while(valor >= 50){
        notas[1] = notas[1] + 1;
        valor -=50;
	}
    while(valor >= 20){
        notas[2] = notas[2] + 1;
        valor -=20;
	}
    while(valor >= 10){
        notas[3] = notas[3] + 1;
        valor -=10;
	}
    while(valor >= 5){
        notas[4] = notas[4] + 1;
        valor -=5;
	}
    while(valor >= 2){
        notas[5] = notas[5] + 1;
        valor -=2;
	}
    while(valor >= 1){
        notas[6] = notas[6] + 1;
        valor -=1;
	}

	cout << notas[0] << " nota(s) de R$ 100,00\n";
	cout << notas[1] << " nota(s) de R$ 50,00\n";
	cout << notas[2] << " nota(s) de R$ 20,00\n";
	cout << notas[3] << " nota(s) de R$ 10,00\n";
	cout << notas[4] << " nota(s) de R$ 5,00\n";
	cout << notas[5] << " nota(s) de R$ 2,00\n";
	cout << notas[6] << " nota(s) de R$ 1,00\n";
	return 0;
}
