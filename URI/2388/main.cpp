#include <iostream>

using namespace std;

int main()
{
    int n, v, t, soma = 0;
    cin >> n;
    while(n--) {
        cin >> t >> v;
        soma += (t * v);
    }
    cout << soma << endl;
    return 0;
}
