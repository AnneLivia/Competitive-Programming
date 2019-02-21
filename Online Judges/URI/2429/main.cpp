#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    vector<vector<int>>adj;
    int nv;
public:
    Graph(int nv) : nv(nv) {
        this->adj.assign(nv, vector<int>());
    }

    void createRoad(int u, int v) {
        this->adj[u].push_back(v);
    }

    bool DFS(int v, vector<int>&vi, int& cont) {
        vi[v] = true;
        cont++;
        for (int i = 0; i < (int)this->adj[v].size(); i++) {
            if(!vi[adj[v][i]]) {
                DFS(adj[v][i], vi, cont);
            }
        }
        if(cont != this->nv)
            return false;
        return true; // all vertexes were visited
    }

    Graph transverse() {
        Graph tr(this->nv);
        for (int i = 0; i < this->nv; i++) {
            for (int j = 0; j < (int)this->adj[i].size(); j++) {
                tr.createRoad(adj[i][j], i);
            }
        }
        return tr;
    }

    bool isSCCwithKosaraju() {
        vector<int>vi(this->nv, 0);
        int cont = 0;
        if(DFS(0, vi, cont)) {
            vi.assign(this->nv, 0);
            cont = 0;
            if(this->transverse().DFS(0, vi, cont)) {
                return true;
            }
        }

        return false;
    }
};
int main()
{
    int ncity, u, v;
    cin >> ncity;
    Graph gr(ncity);
    while(ncity--) {
        cin >> u >> v;
        gr.createRoad(--u, --v);
    }

    if(gr.isSCCwithKosaraju()) {
        cout << "S\n";
    } else {
        cout << "N\n";
    }
    return 0;
}
