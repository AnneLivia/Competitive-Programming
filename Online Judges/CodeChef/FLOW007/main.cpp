#include <iostream>

using namespace std;

int main()
{
    int t, res;
    string n, aux;
    cin >> t;
    while(t--) {
        cin >> n;
        aux = "";
        for(int i = n.size() - 1; i >= 0; i--)
            aux+=n[i];
        res = stoi(aux);
        cout << res << endl;
    }
    return 0;
}
