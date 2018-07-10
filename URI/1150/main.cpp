#include <iostream>

using namespace std;

int main()
{
    int x, z, cont = 1, sum = 0;
    cin >> x;
    do {
        cin >> z;
    } while (z <= x);
    sum = x;
    while(sum <= z) {
        x++;
        sum = x + sum;
        cont++;
    }

    cout << cont << endl;
    return 0;
}
