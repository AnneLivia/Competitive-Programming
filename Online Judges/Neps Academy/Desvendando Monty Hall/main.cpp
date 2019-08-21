#include <iostream>

using namespace std;

int main()
{
    int cont = 0, n, x;
    cin >> n;
    while(n--) {
        cin >> x;
        if(x != 1) {
            cont++;
        }
    }
    cout << cont << endl;
    return 0;
}
