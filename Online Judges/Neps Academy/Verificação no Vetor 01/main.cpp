#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int v[50];
    int q, n, t;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cin >> q;
    while(q--) {
        cin >> t;
        if (find(v, v+n, t) != v+n)
            cout << "Sim\n";
        else
            cout << "Nao\n";
    }
    return 0;
}
