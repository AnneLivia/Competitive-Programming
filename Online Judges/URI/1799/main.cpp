#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > v, v2;
map<string, int> m;

int bfs(int en, int de) {
    vector<int> dist((int)v.size(), -1);
    queue<int>q;
    dist[en] = 0;
    q.push(en);

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < (int)v[u].size(); i++) {
            if(dist[v[u][i]] == -1) {
                dist[v[u][i]] = dist[u] + 1;
                q.push(v[u][i]);
            }
        }
    }

    return dist[de];
}

int main()
{
    int pontos, ligacoes, index = 0, en, sa, qe;
    string s1, s2;
    cin >> pontos >> ligacoes;
    v.assign(pontos, vector<int>());

    while(ligacoes--) {
        cin >> s1 >> s2;
        if(m.find(s1) == m.end()) {
            m.insert({s1,index++});
        }
        if(m.find(s2) == m.end()) {
            m.insert({s2, index++});
        }

        v[m.at(s1)].push_back(m.at(s2));
        v[m.at(s2)].push_back(m.at(s1));

        if(s1 == "Entrada") {
            en = m.at(s1);
        } else if (s1 == "Saida") {
            sa = m.at(s1);
        } else if (s1 == "*") {
            qe = m.at(s1);
        }

        if (s2 == "Entrada") {
            en = m.at(s2);
        } else if (s2 == "Saida") {
            sa = m.at(s2);
        } else if (s2 == "*") {
            qe = m.at(s2);
        }
    }

    cout << bfs(en, qe) + bfs(qe, sa) << endl;
    return 0;
}
