#include <iostream>

using namespace std;

int main()
{
    int n, pm, x, y, cont = 0;
    cin >> n >> pm;
    while(n--) {
        cin >> x >> y;
        if(x + y >= pm)
            cont++;
    }
    cout << cont << endl;
    return 0;
}
