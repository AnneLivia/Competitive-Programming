#include <iostream>
#include <vector>

using namespace std;

typedef vector<char> vc;
typedef vector<int> vi;
vector<vc>v;
vector<vi>vis;
int cont = 0, contt = -1;

void dfs(int i, int j){

    vis[i][j] = 1;
    if(cont > contt)
        contt = cont;

    if(j + 1 < (int)v[i].size() && v[i][j + 1] != 'A' && !vis[i][j + 1]) {
        if(v[i][j + 1] == 'o')
            cont++;
        dfs(i,j+1);
    } else if (j + 1 < (int)v[i].size() && v[i][j + 1] == 'A' && !vis[i][j + 1]) {

        cont = 0;
        dfs(i,j+1);
    }

    if(j - 1 >= 0 && v[i][j - 1] != 'A' && !vis[i][j - 1]) {
        if(v[i][j - 1] == 'o')
            cont++;
        dfs(i,j - 1);

    } else if (j - 1 >= 0 && v[i][j - 1] == 'A' && !vis[i][j - 1]) {

        cont = 0;
        dfs(i,j - 1);
    }

    if(i + 1 < (int)v.size() && v[i + 1][j] != 'A' && !vis[i + 1][j]) {
        if(v[i + 1][j] == 'o')
            cont++;
        dfs(i+1,j);
    } else if (i + 1 < (int)v.size() && v[i + 1][j] == 'A' && !vis[i + 1][j]) {
        cont = 0;
        dfs(i+1,j);
    }


}

int main()
{
    int n;
    cin >> n;
    v.assign(n,vc());
    vis.assign(n,vi());

    for ( int i = 0; i < n; i++) {
        v[i].resize(n);
        vis[i].resize(n);
    }

    for ( int i = 0; i < n; i++) {
        for ( int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }


    dfs(0,0);

    cout << contt << endl;
    return 0;
}
