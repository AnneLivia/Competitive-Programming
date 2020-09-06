#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > g, vi;
int qtd;

void bfs(int x, int y) {
    if(!vi[x][y]) {
        qtd++;
        vi[x][y] = 1;
        int row[8] = {1, -1, 0,  0, 1, -1, 1, -1};
        int col[8] = {0,  0, 1, -1,-1,  1, 1, -1};

        for (int i = 0; i < 8; i++)
        {
            int movex = row[i] + x;
            int movey = col[i] + y;

            if (movex < 0 || movex >= (int)g.size() ||
                movex < 0 || movey >= (int)g[0].size() ||
                vi[movex][movey] || g[movex][movey] == 1) {
                continue;
            }
            
            bfs(movex, movey);
        }
        
    }
}

int main() {
    int n, m, x, y, k, a, b;
    cin >> n >> m >> x >> y >> k;
    g.assign(n, vector<int>(m, 0));
    vi.assign(n, vector<int>(m, 0));

    --x; --y;
    while(k--) {
        cin >> a >> b;
        --a; --b;
        g[a][b] = 1;
    }
    qtd = 0;
    bfs(x, y);
    cout << qtd << endl;
    return 0;  
}
