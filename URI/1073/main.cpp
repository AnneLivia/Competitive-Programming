#include <iostream>
#include "stdio.h"
using namespace std;


int main()
{
    long int n;

    do {
        cin >> n;
    }while(n <= 5 && n > 2000);

    for(int i = 1; i <= n; i++) {
        if(i % 2 == 0) {
            cout << i << "^" << "2 = " << i * i << endl;
        }
    }
    return 0;
}
