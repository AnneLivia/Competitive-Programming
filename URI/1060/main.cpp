#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main() {
    float n[6];
    int cont = 0;
    for ( int i = 0; i < 6; i++)
    {
        cin >> n[i];
    }
    for ( int i = 0; i < 6; i++)
    {
        if(n[i] != 0 && n[i] > 0)
            cont++;
    }
    cout << cont << " valores positivos\n";
	return 0;
}
