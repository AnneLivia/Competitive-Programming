#include <iostream>
#include <vector>

using namespace std;

typedef vector<char> vc;
typedef vector<int> vi;
vector<vc>v;
vector<vi>vis;
bool dir, lef, up, down;

void print() {
    for ( int i = 0; i < (int)v.size(); i++) {
        for ( int j = 0; j < (int)v[i].size(); j++) {
            cout << v[i][j];
        }
        cout << endl;
    }
    cout << "@\n";
}

void dfs(int x, int y) {
    if(v[(int)v.size() - 1][(int)v.size()] != 'X') {
        vis[x][y] = 1;
        print();
        v[x][y] = 'O';

        if(!dir && y + 1 < (int)v.size() && !vis[x][y+1]) {
            v[x][y+1] = 'X';
            up = false;
            dir = true;
            dfs(x,y+1);
        }

        if(!dir) {
            v[x+1][y] = 'X';
            dfs(x+1,y);
        }

        if(!up && x - 1 >= 0 && !vis[x - 1][y]) {
            v[x-1][y] = 'X';
            up = true;
            lef = false;
            dfs(x-1,y);
        }

        if(!up) {
            v[x][y+1] = 'X';
            dfs(x,y+1);
        }

        if(!lef && y - 1 >= 0 && !vis[x][y-1]) {
            v[x][y-1] = 'X';
            down = false;
            lef = true;
            dfs(x,y-1);
        }

        if(!lef) {
            v[x-1][y] = 'X';
            dfs(x-1,y);
        }

        if(!down && x + 1 < (int)v.size() && !vis[x+1][y]) {
            v[x+1][y] = 'X';
            dir = false;
            down = true;
            dfs(x+1,y);
        }

        if(!down) {
            v[x][y-1] = 'X';
            dfs(x,y-1);
        }
    }
}

int main()
{
    int n;
    while(cin >> n && n) {
        v.clear();
        vis.clear();
        dir = false;
        lef = up = down = true;
        v.assign(n,vc());
        vis.assign(n,vi());
        for ( int i = 0; i < n; i++) {
            vis[i].resize(n);
            for(int j = 0; j < n; j++) {
                if(i == n/2 && j == n/2)
                    v[i].push_back('X');
                else
                    v[i].push_back('O');
            }
        }

        if(n != 1)
            dfs(n/2,n/2);
        else
            print();
    }
    return 0;
}
