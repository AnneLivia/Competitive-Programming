#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, c, t, qtd = 0;
    cin >> n >> c;
    vector<int>v(c+1, 0);
    for (int i = 0; i < n; i++) {
        cin >> t;
        v[t]++;
    }
    
    while(true) {
        bool cant = false;
        for (int i = 1; i < c+1; i++) {
            v[i]-=1;
            if (v[i] < 0) {
                cant = true;
                break;
            }
        }
        if (cant)
            break;
        qtd++;
    }
    cout << qtd << endl;
    return 0;  
}
