#include <iostream>
#include <vector>

using namespace std;

vector<vector<char> > grid;
vector<vector<int> > vi;

void move_robot(const char& o,  int& x,  int& y, int& obj);
void change_direction(const char & d, char& o);

int main() {
    int n, m, s, x, y, obj;
    char o, d;
    while(cin >> n >> m >> s && n && m && s) {
        obj = x = y = 0;
        grid.assign(n, vector<char>(m, '.'));
        vi.assign(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> grid[i][j];
                if(isalpha(grid[i][j])) {
                    o = grid[i][j];
                    x = i; y = j;
                }
            }
        }
        while(s--) {
            cin >> d;
            if(d != 'F')
                change_direction(d, o);
            else
                move_robot(o, x, y, obj);
        }
        cout << obj << endl;
    }
    return 0;
}

void change_direction(const char & d, char& o) {
    if(d == 'E') {
        if(o == 'N')
            o = 'O';
        else if (o == 'S') {
            o = 'L';
        } else if (o == 'L') {
            o = 'N';
        } else {
            o = 'S';
        }
    } else {
        if(o == 'N')
            o = 'L';
        else if (o == 'S') {
            o = 'O';
        } else if (o == 'L') {
            o = 'S';
        } else {
            o = 'N';
        }
    }
}

void move_robot(const char& o,  int& x,  int& y, int& obj) {
    int line = 0, col = 0;
    if(o == 'N') {
        line = -1;
        col = 0;
    } else if (o == 'S') {
        line = 1;
        col = 0;
    } else if (o == 'L') {
        line = 0;
        col = 1;
    } else {
        line = 0;
        col = -1;
    }

    if(x + line >= 0 && x + line < (int)grid.size() &&
        y + col >= 0 && y + col < (int)grid[0].size()) {
        if(grid[x+line][y + col] != '#') {
            if(grid[x+line][y + col] == '*' && !vi[x + line][y + col]) {
                vi[x + line][y + col] = 1;
                obj++;
            }
            x = x + line;
            y = y + col;
        }
    }
}
