#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>v(n, 0), aux;
    // 1 - black, -1 white
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    
    for (int i = 1; i < n+1; i++)
    {
        aux.assign(n-i, 0);
        for (int j = 0; j < aux.size(); j++) {
            if (v[j] != v[j + 1]) {
                aux[j] = -1;
            } else {
                aux[j] = 1;
            }
        }
        v = aux;
    }
    
    if (v[0] == -1)
        cout << "branca\n";
    else
        cout << "preta\n";
    
    
    return 0;  
}
