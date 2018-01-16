#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main() {
    double n1,n2,n3, delta, raiz1, raiz2;
    cin >> n1 >> n2 >> n3;

    delta = (n2 *  n2) - (4 * (n1 * n3));
    if(delta < 0)
        cout << "Impossivel calcular\n";
    else if(n1 == 0)
        cout << "Impossivel calcular\n";
    else {
        raiz1 = (-n2 + sqrt(delta)) / (2 * n1);
        raiz2 = (-n2 - sqrt(delta)) / (2 * n1);
        printf("R1 = %.5f\n",raiz1);
        printf("R2 = %.5f\n",raiz2);
    }
	return 0;
}
