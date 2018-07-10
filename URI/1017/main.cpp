#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    int hora, vMedia;
    double litrosGastos;
    cin >> hora;
    cin >> vMedia;

    litrosGastos = (hora * vMedia) / 12.0;
    printf("%.3f\n",litrosGastos);
	return 0;
}
