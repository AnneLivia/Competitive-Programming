#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main() {
    double n1,n2;
    cin >> n1 >> n2;

    if(n1 > 0 && n2 > 0)
        cout << "Q1\n";
    else if(n1 > 0 && n2 < 0)
        cout << "Q4\n";
    else if(n1 < 0 && n2 > 0)
        cout << "Q2\n";
    else if(n1 < 0 && n2 < 0)
        cout << "Q3\n";
    else if(n1 == 0 && n2 == 0)
        cout << "Origem\n";
    else if(n1 != 0 && n2 == 0)
        cout << "Eixo X\n";
    else if(n1 == 0 && n2 != 0)
        cout << "Eixo Y\n";
	return 0;
}
