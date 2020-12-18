#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, ini, fim, cont = 0;
    cin >> n >> ini >> fim;
    vector<int>v(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                int sum = v[i] + v[j];
                if (sum >= ini && sum <= fim)
                    cont++;
            }
        }
    }
    cout << cont/2 << endl;
    return 0;
}