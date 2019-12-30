#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > grid;
vector<vector<int> > vi;

int cont = 0, row[] = {-1, 1, 0, 0}, col[] = {0, 0, 1, -1};

void path(int ei, int ej) {
    if(grid[ei][ej] != 2 && !vi[ei][ej]) {
        vi[ei][ej] = 1;
        for (int i = 0; i < 4; i++) {
            int pi = ei + row[i];
            int pj = ej + col[i];

            if(pi >= 0 && pj >= 0 && pi < (int)grid.size() && pj < (int)grid[0].size()) {
                if(!vi[pi][pj] && grid[pi][pj] != 0) {
                    cont++;
                    path(pi,pj);
                }
            }
        }
    }
}

int main()
{
    int n, m, ei, ej;
    cin >> n >> m;

    grid.assign(n, vector<int>(m, 0));
    vi.assign(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 3) {
                ei = i;
                ej = j;
            }
        }
    }
    path(ei, ej);
    cout << cont + 1 << endl;
    return 0;
}
