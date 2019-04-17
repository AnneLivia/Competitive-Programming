#include <iostream>
#include <vector>

using namespace std;

vector<vector<char> > grid;
vector<vector<int> > vi;
int largura, altura;


bool dfs(int x, int y, char direction) {
    bool res = false;
    if(grid[x][y] == '*')  {
        return true;
    }
    if(vi[x][y] && grid[x][y] != '.') {
        return false; // it's returning
    } else {
        vi[x][y] = 1;
    }

    if(direction == '>') {
        if(y + 1 < largura) {
            if(grid[x][y + 1] == '.') {
                res = dfs(x, y + 1, direction);
            } else {
                res = dfs(x, y + 1, grid[x][y+1]);
            }
        }
    } else if (direction == 'v') {
        if(x + 1 < altura) {
            if( grid[x + 1][y] == '.') {
               res = dfs(x + 1, y, direction);
            } else {
                res = dfs(x + 1, y, grid[x + 1][y]);
            }
        }
    } else if (direction == '<') {
        if (y - 1 >= 0 ) {
            if( grid[x][y - 1] == '.') {
                res = dfs(x, y - 1, direction);
            } else {
                res = dfs(x, y - 1, grid[x][y - 1]);
            }
        }
    } else if (direction == '^') {
        if( x - 1 >= 0) {
            if( grid[x - 1][y] == '.') {
                res = dfs(x - 1, y, direction);
            } else {
                res = dfs(x - 1, y, grid[x - 1][y]);
            }
        }
    }
    return res;
}

int main()
{

    cin >> largura >> altura;

    grid.assign(altura, vector<char>(largura, '.'));
    vi.assign(altura, vector<int>(largura, 0));

    for (int i = 0; i < altura; i++) {
        for(int j = 0; j < largura; j++) {
            cin >> grid[i][j];
        }
    }

    if(dfs(0, 0, grid[0][0]))
        cout << "*\n";
    else
        cout << "!\n";

    return 0;
}
