#include <iostream>
#include <vector>

using namespace std;

int kadane(const vector<int>& v) {
    int aux = 0, total = 0;

    for (int i = 0; i < (int)v.size(); i++)
    {
        aux+=v[i];
        if (aux < 0)
            aux = 0;
        if (total <= aux) {
            total = aux;
        }
    }

    return total;
}

int main() {
    int n;
    cin >> n;
    vector<int>v(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    
    cout << kadane(v) << endl;
    return 0;  
}
