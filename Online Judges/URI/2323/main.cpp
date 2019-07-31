#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

vector<vector<int> > g;

int dfs(int v) {
    vector<int>vi((int)g.size(), 0);
    int qtdChild = 0;
    stack<int>s;
    s.push(v);

    while(!s.empty()) {
        int v = s.top();
        s.pop();
        if(!vi[v]) {
            vi[v] = 1;
        }

        for (int i = 0; i < (int)g[v].size(); i++) {
            int u = g[v][i];
            if(!vi[u]) {
                s.push(u);
                qtdChild++;
            }
        }
    }
    return qtdChild;
}

bool check_balance() {
    queue<int>q;

    vector<int>qtd((int)g.size(), 0);

    q.push(0);

    while(!q.empty()) {
        int v = q.front();
        q.pop();

        if(!qtd[v]) {
            qtd[v] = 1;

           // cout << "Checking " << v << ":\nChild:    ";
            int child = -1;
            for (int i = 0; i < (int)g[v].size(); i++) {
                int u = g[v][i];
              //  cout << u << " -> " << dfs(u) << endl;;
                if(child == -1)
                    child = dfs(u);
                else {
                    if((int)dfs(u) != child)
                        return false;
                }
                q.push(u);
            }
        }
    }

    return true;
}

int main()
{
    int n, x, y;
    cin >> n;

    g.assign(n + 1, vector<int>());

    while(n--) {
        cin >> x >> y;
        g[y].push_back(x);
    }

    if(check_balance())
        cout << "bem\n";
    else
        cout << "mal\n";

    return 0;
}
