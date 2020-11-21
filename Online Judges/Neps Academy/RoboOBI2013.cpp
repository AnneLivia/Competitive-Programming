#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > v;
vector<vector<int> > vi;

void dfs(int x, int y) {
    bool foundany = false;  
    if (!vi[x][y]) {
        vi[x][y] = 1;
        int row[4] = {1, -1, 0, 0}, col[4] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++)
        {
           int xx = x + row[i];
           int yy = y + col[i];

           if (xx >= 0 && xx < (int)v.size() && yy >= 0 && yy < (int)v[0].size()
              && v[xx][yy] == 1 && !vi[xx][yy]) {
                  dfs(xx, yy);
                  foundany = true;
            } 
        }

        if (!foundany) {
            cout << x + 1 << " " << y + 1 << endl;
        }
    }
    
}

int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    v.assign(n, vector<int>(m, 0));
    vi.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    --x, --y;
    dfs(x, y);
    return 0;  
}
