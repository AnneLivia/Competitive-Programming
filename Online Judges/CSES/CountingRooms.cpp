#include <iostream>
#include <vector>

using namespace std;
vector<vector<char> > v;
vector<vector<int > > vi;

int n, m;

void dfs(int i, int j) {
    vi[i][j] = 1;

    int row[] = {1, 0, -1, 0}, col[] = {0, 1, 0, -1};

    for (int k = 0; k < 4; k++) {
        int x = row[k] + i;
        int y = col[k] + j;

        if (x >= 0 && x < n && y >= 0 && y < m) {
            if(!vi[x][y] && v[x][y] == '.') {
                dfs(x,y);
            }
        }
    }
}

int main() {
    
    cin >> n >> m;

    int cont_room = 0;

    v.assign(n, vector<char>(m, '.'));
    vi.assign(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == '.' && !vi[i][j]) {
                dfs(i, j);
                cont_room++;
            }
        }
    }

    cout << cont_room << endl;

    return 0;
}