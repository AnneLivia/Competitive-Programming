#include <iostream>
#include <vector>

using namespace std;

int v[1002][1002], vi[1002][1002];

int n, m, qtd;

void bfs(int x, int y) {
   v[x][y] = qtd;
   vi[x][y] = 1;
   int row[4] = {1, -1, 0, 0}, col[4] = {0, 0, 1, -1};
   for (int i = 0; i < 4; i++)
   {
       int movex = row[i] + x;
       int movey = col[i] + y;

       if (movex >= 0 && movex < n &&
           movey >= 0 && movey < m &&
           v[movex][movey] == 1 && !vi[movex][movey]) {
           bfs(movex, movey);
        }
   }
   
}

int main() {
    qtd = 1;
    cin >> n >> m;
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            v[i][j] = 0;
            vi[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(v[i][j] == 1) {
                qtd++;
                bfs(i,j);
            }
        }
    }

    cout << qtd - 1 << endl;
    return 0;  
}
