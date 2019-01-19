#include <iostream>
#include "stdio.h"
using namespace std;

int main()
{
    int n[100], maior, pos;

    for(int i = 0; i < 100; i++) {
        cin >> n[i];
        if(i == 0) {
            maior = n[i];
        }
        for ( int j = 0; j < i; j++)
        {
            if(n[i] > maior) {
                maior = n[i];
                pos = i + 1;
            }
        }
    }

    cout << maior << endl << pos << endl;


    return 0;
}
