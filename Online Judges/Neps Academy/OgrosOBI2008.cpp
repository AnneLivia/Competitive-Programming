#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Data {
    long int ini, end, point;
};

vector<Data> v;

int binary(int value) {
    int ini = 0, ennd = (int)v.size() - 1;
    while(ini <= ennd) {
        int m = (ini + ennd) / 2;
        if (v[m].ini <= value && value <= v[m].end)
            return v[m].point;
        else if (value < v[m].ini) {
            ennd = m - 1;
        } else {
            ini = m + 1;
        }
    }
    return 0;
}

int main() {
    int n, p, ogro;
    cin >> n >> p;
    v.assign(n, {0, 0x3f3f3f3f, 0});
    // 3 5
    for (int i = 0; i < n-1; i++) {
        cin >> v[i].end;
        v[i].end--; // end limit
        if (i != 0) {
            v[i].ini = v[i - 1].end + 1;
        }
    }

    v[n - 1].ini = v[n - 2].end + 1;

    for (int i = 0; i < n; i++) {
        cin >> v[i].point;
    }
    
    for (int i = 0; i < p; i++) {
        cin >> ogro;
        if (i != 0)
            cout << " ";
        cout << binary(ogro);
    }
    cout << endl;
    return 0;  
}
