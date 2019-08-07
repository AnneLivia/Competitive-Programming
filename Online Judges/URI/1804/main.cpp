#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<int>bit;

void update(int index, int value, int previous = 0) {
    while(index < (int)bit.size()) {
        bit[index]-=previous;
        bit[index]+=value;
        index+=index&(-index);
    }
}

int sum(int p) {
    int cont = 0;
    while(p > 0) {
        cont+=bit[p];
        p -= p & (-p);
    }
    return cont;
}

int main()
{
    ios::sync_with_stdio(0);
    int n, p;
    char a;
    vector<int>v;
    cin >> n;

    v.assign(n, 0);
    bit.assign(n + 1, 0);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // building BIT
    for (int i = 1; i <= n; i++) {
        update(i, v[i - 1]);
    }

    while(cin >> a >> p) {
        if(a == 'a') {
            update(p, 0, v[p - 1]);
        } else {
            cout << sum(p - 1) << endl;
        }
    }
    return 0;
}
