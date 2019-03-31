#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > gra;
vector<int>vi;

void bfsUtil(int v) {
    queue<int>q;
    q.push(v);

    while(!q.empty()) {
        int va = q.front();
        q.pop();
        if(!vi[va]) {
            vi[va] = 1;
        }
        for (int i = 0; i < (int)gra[va].size(); i++) {
            if(!vi[gra[va][i]]) {
                q.push(gra[va][i]);
            }
        }
    }
}

int bfs() {
    vi.assign((int)gra.size(), 0);
    int comp = 0;

    for (int i = 0; i < (int)gra.size(); i++) {
        if(!vi[i]) {
            bfsUtil(i);
            comp++;
        }
    }
    return comp;
}


int main()
{
    int n, m, t, x, y, c = 1;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        gra.assign(n, vector<int>());
        while(m--) {
            cin >> x >> y;
            gra[x - 1].push_back(y - 1);
            gra[y - 1].push_back(x - 1);
        }
        cout << "Caso #" << c++ << ": ";
        int r = bfs() - 1;
        if(r == 0)
            cout << "a promessa foi cumprida\n";
        else
            cout << "ainda falta(m) " << r << " estrada(s)\n";
    }
    return 0;
}
