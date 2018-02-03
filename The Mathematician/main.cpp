#include <iostream>

using namespace std;

int main()
{
    int n, x,y, cont;
    char c;
    cin >> n;
    while(n--) {
        cin >> x >> c >> y;
        cont = 5;
        while(cont <= 10) {
            if(y != x)
                cout << x << " x " << cont << " = " << x * cont << " && " << y << " x " << cont << " = " << y * cont << endl;
            else
                cout << x << " x " << cont << " = " << x * cont << endl;
            cont++;
        }
    }
    return 0;
}
