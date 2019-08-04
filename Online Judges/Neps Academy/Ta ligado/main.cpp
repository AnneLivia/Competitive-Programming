#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > pontes;

bool is_part(int a, int b) {
    for (int i = 0; i < (int)pontes[a].size(); i++) {
        if(pontes[a][i] == b)
            return true;
    }
    return false;
}

int main()
{
    int n, m, a, b, t;

    cin >> n >> m;

    pontes.assign(n + 1, vector<int>());

    while(m--) {
        cin >> t >> a >> b;

        if(t == 0) {
            if(is_part(a, b)) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        } else {
            pontes[a].push_back(b);
            pontes[b].push_back(a);
        }
    }
    return 0;
}
