#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<vector<int> >g;
vector<int>vi;

void dfs(int v) {
    vi[v] = true;
    for (int i = 0; i < (int)g[v].size(); i++) {
        if(!vi[g[v][i]])
            dfs(g[v][i]);
    }
}
int main()
{
    int n, m, index = 0, cont = 0;
    string v, relation, w;
    map<string,int>names;
    cin >> n >> m;
    g.assign(n, vector<int>());
    while(m--) {
        cin >> v >> relation >> w;
        if(names.find(v) == names.end())
            names.insert(make_pair(v, index++));
        if(names.find(w) == names.end())
            names.insert(make_pair(w, index++));
        g[names.at(v)].push_back(names.at(w));
        g[names.at(w)].push_back(names.at(v));
    }

    vi.assign(n, 0);
    for (int i = 0; i < n; i++) {
        if(!vi[i]) {
            dfs(i);
            cont++;
        }
    }
    cout << cont << endl;
    return 0;
}
