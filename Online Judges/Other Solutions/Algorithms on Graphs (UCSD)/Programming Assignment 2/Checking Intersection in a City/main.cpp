#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

/*
    The police department of a city has made all streets one-way.
    You would like to check whether it is still possible to drive
    legally from any intersection to any other intersection.
    For this, you construct a directed graph: vertices are
    intersections, there is an edge (u,v) whenever there is a
    (one-way) street from u to v in the city. Then, it suffices
    to check whether all the vertices in the graph lie in the
    same strongly connected component.

    Compute the number of strongly connected components of a given
    directed graph with n vertices and m edges.
*/

class Graph {
private:
    list<int>*intersections;
    int nv;
public:
    Graph(int nv) : nv(nv) {
        this->intersections = new list<int>[nv];
    }

    void createEdge(int u, int v) {
        this->intersections[u].push_back(v);
    }

    Graph transpose() {
        Graph tGraph(this->nv);
        for (int i = 0; i < this->nv; i++) {
            for(auto it : this->intersections[i]) {
                tGraph.createEdge(it, i);
            }
        }
        return tGraph;
    }

    void dfs(int v, vector<int>& vi, stack<int>& s, int turn) {
        vi[v] = true;
        for(auto it : intersections[v]) {
            if(!vi[it])
                dfs(it,vi,s,turn);
        }
        if(turn == 1)
            s.push(v);
    }

    int kosaraju() {
        vector<int>vi(this->nv, 0);
        stack<int>s;
        int scc = 0;
        for (int i = 0; i < this->nv; i++) {
            if(!vi[i])
                dfs(i, vi, s, 1);
        }
        Graph tGraph = this->transpose();
        vi.assign(this->nv, 0);
        while(!s.empty()) {
            int vertex = s.top();
            s.pop();
            if(!vi[vertex]) {
                tGraph.dfs(vertex, vi, s, 0);
                scc++;
            }
        }
        return scc;
    }

    ~Graph() {
        delete[] intersections;
    }
};

int main()
{
    int nVertices, nEdges, u, v;
    cin >> nVertices >> nEdges;
    Graph gf(nVertices);
    while(nEdges--) {
        cin >> u >> v;
        gf.createEdge(--u, --v);
    }

    cout << gf.kosaraju() << endl;
    return 0;
}
