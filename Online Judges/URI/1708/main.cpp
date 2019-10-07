#include <iostream>

using namespace std;

int main()
{
    int x, y, cont = 1;
    cin >> x >> y;
    while((cont * max(x,y) - cont * min(x,y)) < max(x,y)) {
        cont++;
    }
    cout << cont << endl;
    return 0;
}
