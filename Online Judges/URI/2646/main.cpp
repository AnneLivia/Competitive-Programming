#include <iostream>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

vector<vector<int>>g;


/*
    2646 - Secret Chamber at Mount Rushmore (URI)
*/

bool dfs(int v, int x) {
    vector<int>vi(26,0);
    stack<int>s;
    s.push(v);
    if(v == x)
        return true;
    while(!s.empty()) {
        v = s.top();
        s.pop();
        if(!vi[v]) {
            vi[v] = 1;
        }
        for (int i = 0; i < (int)g[v].size(); i++) {
            if(g[v][i] == x) {
                return true;
            } else if(!vi[g[v][i]]) {
                s.push(g[v][i]);
            }
        }
    }
    return false;
}

int main()
{
    int m, n, u, v;
    char c;
    string s1, s2;

    while(cin >> m >> n){
        g.assign(26, vector<int>());
        while(m--) {
            cin >> c; u = (int)c - 'a';
            cin >> c; v = (int)c - 'a';
            g[u].push_back(v);
        }

        while(n--) {
            bool are = true;
            cin >> s1 >> s2;
            if((int)s1.size() == (int)s2.size()) {
                for (int i = 0; i < (int)s1.size(); i++) {
                    u = (int)(s1[i] - 'a');
                    v = (int)(s2[i] - 'a');
                    if(!dfs(u,v)) {
                        are = false;
                        break;
                    }
                }
            } else {
                are = false;
            }

            if(are) {
                cout << "yes\n";
            } else {
                cout << "no\n";
            }
        }
    }
    return 0;
}
