#include <iostream>
#include <vector>

using namespace std;

vector<vector<char> > v;
vector<vector<int> > vi;

int main() {
    int n, m, s, posi, posj;
    char c, dir;
    while(cin >> n >> m >> s && n && m && s) {
        int card = 0;
        v.assign(n, vector<char>(m, '.'));
        vi.assign(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> v[i][j];
                if (v[i][j] != '*' && v[i][j] != '#' && v[i][j] != '.') {
                    posi = i;
                    posj = j;
                    dir = v[i][j];
                }
            }
        }

        while(s--) {
            cin >> c;
            if (c == 'D') {
                if (dir == 'N')
                    dir = 'L';
                else if (dir == 'L') {
                    dir = 'S';
                } else if (dir == 'S') {
                    dir = 'O';
                } else {
                    dir = 'N';
                }
            } else if (c == 'E') {
                if (dir == 'N')
                    dir = 'O';
                else if (dir == 'O') {
                    dir = 'S';
                } else if (dir == 'S') {
                    dir = 'L';
                } else {
                    dir = 'N';
                }
            } else {
                if (dir == 'N') {
                    if (posi - 1 >= 0 && v[posi - 1][posj] != '#') {
                        posi-=1;
                        if (v[posi][posj] == '*') {
                           v[posi][posj] = '.';
                           card++;
                        }
                    }
                } else if (dir == 'O') {
                    if (posj - 1 >= 0 && v[posi][posj - 1] != '#') {
                        posj-=1;
                        if (v[posi][posj] == '*') {
                           v[posi][posj] = '.';
                           card++;
                        }
                    }
                } else if (dir == 'S') {
                    if (posi + 1 < n && v[posi + 1][posj] != '#') {
                        posi+=1;
                        if (v[posi][posj] == '*') {
                           v[posi][posj] = '.';
                           card++;
                        }
                    }
                } else if (dir == 'L'){
                    if (posj + 1 < m && v[posi][posj + 1] != '#') {
                        posj+=1;
                        if (v[posi][posj] == '*') {
                           v[posi][posj] = '.';
                           card++;
                        }
                    }
                }

            }
        }

        cout << card << endl;
    }
}
