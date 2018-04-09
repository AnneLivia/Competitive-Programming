#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
vector<vi>v, vis;

int co;

void dfs(int p1, int p2) {

    if(p1 >= 0 && p1 < 5 && p2 >= 0 && p2 < 5 && !co) {

        vis[p1][p2] = 1;
        if(p1 == 4 && p2 == 4) {
            co = 1;
        } else {
            // Baixo
            if( p1 + 1 < 5 && v[p1 + 1][p2] == 0 && vis[p1 + 1][p2] == 0)
                dfs(p1+1,p2);
            // Cima
            if( p1 - 1 >= 0 && v[p1 - 1][p2] == 0 && vis[p1 - 1][p2] == 0)
                dfs(p1 - 1,p2);
            // Direita
            if( p2 + 1 < 5 && v[p1][p2 + 1] == 0 && vis[p1][p2 + 1] == 0)
                dfs(p1,p2 + 1);
            // Esquerda
            if( p2 - 1 >= 0 && v[p1][p2 - 1] == 0 && vis[p1][p2 - 1] == 0)
                dfs(p1,p2 - 1);
        }
    }
}

int main()
{
    int t, n;
    cin >> t;

    while(t--) {
        v.assign(5,vi());
        vis.assign(5,vi());

        for ( int i = 0; i < 5; i++) {
            v[i].resize(5);
            vis[i].resize(5);
        }

        for ( int i = 0; i < 5; i++) {
            for ( int j = 0; j < 5; j++) {
                cin >> n;
                v[i][j] = n;
            }
        }

        co = 0;

        dfs(0, 0);
        if(co)
            cout << "COPS\n";
        else
            cout << "ROBBERS\n";
    }



    return 0;
}
