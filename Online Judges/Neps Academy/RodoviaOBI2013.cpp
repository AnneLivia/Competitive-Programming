#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int> > g;

int n, lastDigitFirst;  

int dfs_aux(int t) {
    vector<int> vi(n+1, 0);
    stack<int>s;
    s.push(t);
    int qtdvertex = 0;

    while(!s.empty()) {
        int u = s.top();
        s.pop();

        if (!vi[u]) {
            vi[u] = 1;
            qtdvertex++;
        }

        for (int i = 0; i < g[u].size(); i++)
        {
            int v = g[u][i];

            if (!vi[v]) {
                s.push(v);
            }
        }

        if (s.empty()) {
            lastDigitFirst = u;
        }
    }

    return qtdvertex;
}

bool dfs() {
    int qtd1 = dfs_aux(1);
    int qtd2 = dfs_aux(lastDigitFirst);
    return qtd1 == n && qtd2 == n;
}

int main() {
    int a, b;
    cin >> n;
    g.assign(n+1, vector<int>());
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b;   
        g[a].push_back(b);
    }
    
    if (dfs()) {
        cout << "S\n";
    } else {
        cout << "N\n";
    }

    return 0;  
}
