#include <iostream>
#include <vector>

using namespace std;

// description of the problem: https://neps.academy/br/exercise/57

vector<vector<int > > v, vi;

int cont = 0, resp = 0;

void contPathStars(int x, int y) {
    if (!vi[x][y]) {
        vi[x][y] = 1;
        cont+=1;

        if (v[x][y] == 3)
           resp = cont;
        // first left, right then up and down
        int vert[4] = {-1, 1, 0, 0};
        int hori[4] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            // verify if it was already seen
            if (vert[i] + x >= 0 && vert[i] + x < (int)v.size() &&  // if is in the range of rows
                hori[i] + y >= 0 && hori[i] + y < (int)v[0].size() && // if is in the range of cols
                !vi[vert[i] + x][hori[i] + y] && // if it was not visited
                (v[vert[i]+x][hori[i] + y] == 1 ||
                 v[vert[i]+x][hori[i] + y] == 3)
            ) {
                contPathStars(vert[i]+x, hori[i] + y);
            }
        }
    }
    cont--;
}

int main () {

    int n, m, xStart = 0, yStart = 0;

    cin >> n >> m;

    v.assign(n, vector<int>(m, 0));
    vi.assign(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            if (v[i][j] == 2) {
               xStart = i;
               yStart = j;
            }
        }
    }

    contPathStars(xStart, yStart);
    cout <<  resp << endl;
    return 0;
}

