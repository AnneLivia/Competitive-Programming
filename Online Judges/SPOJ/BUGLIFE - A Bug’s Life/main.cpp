#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
typedef vector<int> vi;
vector<vi>g;
vector<int>col;

bool dfsUtil(int source) {
    stack<int>s;
    s.push(source);
    col[source] = 1;
    while(!s.empty()) {
        int u = s.top();
        s.pop();

        for (int i = 0; i < (int)g[u].size(); i++) {
            int v = g[u][i];
            // It also keep track of which one was visited (if its color is -1, then it was not visited)
            if(col[v] == -1) { // There's no color yet, assign it the opposite of the color of u
                col[v] =  1 - col[u]; // Which is 0 or 1
                s.push(v);
            } else { // if it has color
                if(col[v] == col[u]) // if the color of the adjacent is equal to the color of u, then it's not bipartite
                    return false;
            }
        }
    }
    return true;
}

bool bipartite() {
    for (int i = 0; i < (int)g.size(); i++) {
        if(col[i] == -1) {
            if(!dfsUtil(i))
                return false;
        }
    }
    return true;
}

int main()
{
    int t, x, y, e, ver, c = 1;
    cin >> t;
    while(t--) {
        cin >> ver >> e;
        g.assign(ver, vi());
        col.assign(ver, -1);
        while(e--) {
            cin >> x >> y;
            g[x - 1].push_back(y - 1);
            g[y - 1].push_back(x - 1);
        }
        cout << "Scenario #" << c++ << ":\n";
        if(bipartite())
            cout << "No suspicious bugs found!\n";
        else
            cout << "Suspicious bugs found!\n";
    }
    return 0;
}
