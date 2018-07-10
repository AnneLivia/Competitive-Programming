#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main() {
    int h1, h2, cont = 0, copyh1;
    cin >> h1 >> h2;
    copyh1 = h1;

    while(copyh1 != h2)
    {
        if(copyh1 == 24)
            copyh1 = 0;
        else{
            copyh1 +=1;
            cont++;
        }
    }
    if(h1 == h2)
        cont = 24;
    cout << "O JOGO DUROU " << cont << " HORA(S)" << endl;
	return 0;
}
