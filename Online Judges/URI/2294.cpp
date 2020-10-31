#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int> > g;
vector<vector<int> > dist;
vector<pair<int, int> > out;

int bfs(int x, int y) {
    queue<pair<int,int> > q;
    q.push({x,y});
    dist[x][y] = 0;

    while(!q.empty()) {
        pair<int,int> d = q.front();
        q.pop();
        
        
        int row[4] = {1, -1, 0, 0};
        int col[4] = {0,  0, 1,-1};

        if (find(out.begin(), out.end(), d) != out.end())
            return dist[d.first][d.second];
                
        for (int i = 0; i < 4; i++) {
            int movex = row[i] + d.first;
            int movey = col[i] + d.second;

            if (movex < 0 || movex >= (int)dist.size() ||
                movey < 0 || movey >= (int)dist[0].size() ||
                g[movex][movey] == 2 || dist[movex][movey] != -1)
                continue;

            dist[movex][movey] = dist[d.first][d.second] + 1;
            q.push({movex, movey});
        }
    }
    return 0;
}

int main() {
    
    int n, m, xs, ys;
    cin >> n >> m;
    
    g.assign(n, vector<int>(m, 0));
    dist.assign(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 0) {
                out.push_back({i,j});
            } else if (g[i][j] == 3) {
                xs = i, ys = j;
            }
        }
    }

    cout << bfs(xs, ys) << endl;
    return 0;  
}
