#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int>banks;
int find_patr(int v) {
    if(banks[v] == -1)
        return v;
    return banks[v] = find_patr(banks[v]);
}

void join(int v1, int v2) {
    banks[find_patr(v1)] = find_patr(v2);
}

int main()
{
    char c;
    int b1, b2, n, op;
    cin >> n >> op;
    banks.assign(n + 1,-1);
    while(op--) {
        cin >> c >> b1 >> b2;
        if(c == 'F') {
            join(b1, b2);
        } else {
            if(find_patr(b1) == find_patr(b2))
                cout << "S\n";
            else
                cout << "N\n";
        }
    }
    return 0;
}
