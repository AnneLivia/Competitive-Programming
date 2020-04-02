#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<vector<int> >gr;
vector<int>in;

void top() {
    // taking all vextex with indegree 0
    queue<int>q;
    for (int i = 1; i < (int)gr.size(); i++) {
       if (in[i] == 0) {
          q.push(i);
       }
    }
    // ans is going to store topologic sort  
    int ans[100001] = {0};
    int t = 0;
    while(!q.empty()) {
        int v = q.front();
        ans[t++] = v;
        q.pop();

        for(int i = 0; i < (int)gr[v].size(); i++) {
            in[gr[v][i]]--;
            if (in[gr[v][i]] == 0) {
                q.push(gr[v][i]);
            }
        }
    }
    // there's no cycle
    if (t + 1 == (int)gr.size()) {
        for (int i = 0; i < t; i++)
        {
            cout << ans[i] << " ";
        }
    } else {
        cout << "IMPOSSIBLE\n";
    }
}

int main() {
    int n, m, a, b;
    cin >> n >> m;
    gr.assign(n+1, vector<int>());
    in.assign(n + 1, 0);
    while(m--) {
        cin >> a >> b;
        gr[a].push_back(b);
        in[b]++;
    }

    top();
    return 0;  
}
