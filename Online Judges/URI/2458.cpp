#include <iostream>
#include <vector>

using namespace std;

vector<vector<char> > v;
vector<vector<int> > vi;

int countpath, n;

void dfs(int posi, int posj, int ind) {
    vi[posi][posj] = ind;
    if (posi + 1 < n && vi[posi + 1][posj] != ind && v[posi + 1][posj] == 'A') {
        if (vi[posi + 1][posj] == -1)
            countpath++;
        dfs(posi + 1, posj, ind);
    }

    if (posj + 1 < n && vi[posi][posj + 1] != ind && v[posi][posj + 1] == '<') {
        if (vi[posi][posj + 1] == -1)
            countpath++;
        dfs(posi, posj + 1, ind);
    }

    if (posi - 1 >= 0 && vi[posi - 1][posj] != ind && v[posi - 1][posj] == 'V') {
        if (vi[posi - 1][posj] == -1)
            countpath++;
        dfs(posi - 1, posj, ind);
    }

    if (posj - 1 >= 0 && vi[posi][posj - 1] != ind && v[posi][posj - 1] == '>') {
        if (vi[posi][posj - 1] == -1)
            countpath++;
        dfs(posi, posj - 1, ind);
    }
}

int main() {
    int posi, posj;
    cin >> n;
    v.assign(n, vector<char>(n, '.'));
    vi.assign(n, vector<int>(n, -1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    int ind = 1;
    countpath = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == n - 1 && v[i][j] == '>' ||
                i == n - 1 && v[i][j] == 'V' ||
                j == 0 && v[i][j] == '<' ||
                i == 0 && v[i][j] == 'A') {
                posi = i;
                posj = j;
                countpath++;
                dfs(posi, posj, ind++);
            }
        }
    }

    cout << n * n - countpath << endl;
    return 0;  
}
