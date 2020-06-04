#include <iostream>

using namespace std;

int main()
{
    int n, p, qtd = 0, x, y;
    cin >> n >> p;
    while(n--) {
        cin >> x >> y;
        if (x+y >= p)
            qtd++;
    }
    cout << qtd << endl;
    return 0;
}
