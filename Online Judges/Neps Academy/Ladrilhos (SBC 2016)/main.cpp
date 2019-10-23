#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int> > v ;
vector<vector<int> > vi ;
int h, li, cont, cont0;

void bfs(int i, int j) {
    if(!vi[i][j]) {

        cont++;

        vi[i][j] = 1;

        int row[] = {1, -1, 0, 0};
        int col[] = {0, 0, 1, -1};

        for (int t = 0; t < 4; t++) {
            int l = i + row[t];
            int c = j + col[t];

            if(l >= 0 && l < h && c >= 0 && c < li && !vi[l][c] && v[l][c] == v[i][j]) {
                bfs(l,c);
            }
        }
    }
}
int main()
{
    cin >> h >> li;
    v.assign(h, vector<int>(li, 0));
    vi.assign(h, vector<int>(li, 0));
    vector<int>df;
    for (int i = 0; i < h; i++) {
        for(int j = 0; j < li; j++) {
            cin >> v[i][j];
            if(find(df.begin(), df.end(), v[i][j]) == df.end()) {
                df.push_back(v[i][j]);
            }
        }
    }

    int minimum = 100000;
    for (int i = 0; i < h; i++) {
        for(int j = 0; j < li; j++) {
            cont = 0;
            if(!vi[i][j]) {
                bfs(i,j);
                if(cont < minimum && cont != 0) {
                    minimum = cont;
                }
            }
        }
    }

    // just one color and holes

    cout << minimum << endl;

    return 0;
}
