#include <iostream>

using namespace std;

int main()
{
    int pa, pd, n, cont = 0;
    cin >> n >> pd >> pa;

    while(pa != pd) {
        pa++;
        if(pa > n)
            pa = 1;
        cont++;
    }

    cout << cont << endl;
    return 0;
}
