#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


typedef vector<int> vi;

char v[50][50];
int vis[50][50] = {0}, n, m;

void dfs(int x, int j) {
    vis[x][j] = 1;
    // Up
    if(x - 1 >= 0 && v[x - 1][j] == 'A') {
        v[x - 1][j] = 'T';
        dfs(x-1,j);
    }
    // Down
    if(x + 1 < n && v[x + 1][j] == 'A') {
        v[x+1][j] = 'T';
        dfs(x+1,j);
    }
    // left
    if(j - 1 >= 0 && v[x][j - 1] == 'A') {
        v[x][j-1] = 'T';
        dfs(x,j-1);
    }
    // right
    if(j + 1 < m && v[x][j+1] == 'A') {
        v[x][j+1] = 'T';
        dfs(x,j+1);
    }
}

int main()
{
    char c;

    while(true) {
        cin >> n >> m;
        if(n == 0 && m == 0)
            break;

        for ( int i = 0; i < n; i++){
            for ( int j = 0; j < m; j++) {
                cin >> c;
                v[i][j] = c;
            }
        }

        for ( int i = 0; i < n; i++){
            for ( int j = 0; j < m; j++) {
                if(!vis[i][j] && v[i][j] == 'T') {
                    dfs(i,j);
                }
            }
        }

        for ( int i = 0; i < n; i++){
            for ( int j = 0; j < m; j++) {
                cout << v[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
