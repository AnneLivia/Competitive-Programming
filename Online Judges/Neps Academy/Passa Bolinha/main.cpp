#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > v, vi;
int band = 0;

void dfs(int i, int j) {
    vi[i][j] = 1;
    band++;

    int row[] = {0, 0, -1, 1};
    int col[] = {1, -1, 0, 0};

    for (int k = 0; k < 4; k++) {
        int pi = row[k] + i;
        int pj = col[k] + j;
        if(pi >= 0 && pj >= 0 && pi < (int)v.size() && pj < (int)v.size() && !vi[pi][pj] && v[pi][pj] >= v[i][j]) {
            dfs(pi, pj);
        }
    }
}

int main()
{
    // number of cols and rolls
    int n, pi, pj;
    cin >> n >> pi >> pj;

    v.assign(n, vector<int>(n, 0));
    vi.assign(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    dfs(pi - 1, pj - 1);
    cout << band << endl;
    return 0;
}
