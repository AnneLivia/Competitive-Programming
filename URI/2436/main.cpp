#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
vector<vi>v, vis;
int p1, p2;

void dfs(int i, int j) {
    if(!vis[i][j]) {
        vis[i][j] = 1;
    }

    if(v[i][j] == 1) {
        p1 = i; p2 = j;
        if(i - 1 >= 1 && v[i - 1][j] == 1 && !vis[i - 1][j])
            dfs(i - 1,j);
        if(i + 1 < (int)v.size() && v[i + 1][j] == 1 && !vis[i+1][j])
            dfs(i + 1,j);
        if(j - 1 >= 1 && v[i][j - 1] == 1 && !vis[i][j - 1])
            dfs(i,j - 1);
        if(j + 1 < (int)v[i].size() && v[i][j + 1] == 1 && !vis[i][j + 1])
            dfs(i,j + 1);
    }
}

int main()
{
    int l, c, posl, posc;
    cin >> l >> c >> posl >> posc;
    v.assign(l+1,vi());
    vis.assign(l+1,vi());
    for ( int i = 1; i <= l; i++) {
        v[i].resize(c+1);
        vis[i].resize(c+1);
    }

    for ( int i = 1; i <= l; i++) {
        for ( int j = 1; j <= c; j++) {
            cin >> v[i][j];
        }
    }

    dfs(posl,posc);
    cout << p1 << " " << p2 << endl;
    return 0;
}
