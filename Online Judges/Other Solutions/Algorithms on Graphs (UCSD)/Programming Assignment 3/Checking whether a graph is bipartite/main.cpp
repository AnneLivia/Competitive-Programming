#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
    A Bipartite Graph is a graph whose vertexes can be divided
    into two independent sets, U and V such that every edge (u, v)
    either connects a vertex from U to V or a vertex from V to U.
    In other words, for every edge (u, v), either u belongs to U
    and v to V, or u belongs to V and v to U. We can also say that
    there is no edge that connects vertexes of same set.

    Algorithm to check if a graph is Bipartite, when a graph has only 2 colors:
    1 -  Assign RED color to the source vertex (putting into set U).
    2 -  Color all the neighbors with BLUE color (putting into set V).
    3 -  Color all neighbor's neighbor with RED color (putting into set U).
    4 -  This way, assign color to all vertexes such that it satisfies all the constraints of m way coloring problem where m = 2.
    5 - While assigning colors, if we find a neighbor which is colored with same color as current vertex, then the graph cannot be
    colored with 2 vertexes (or graph is not Bipartite)
*/

class Graph {
private:
    vector<vector<int> >g;
    int nv;
public:
    Graph(int nv) : nv(nv) {
        g.assign(nv, vector<int>());
    }

    void addEdge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    void addArc(int u, int v) {
        g[u].push_back(v);
    }

    // Using BFS
    bool isBipartite() {
        // Create a array that will store the colors
        // 0 - No color assign to vertex
        // 1 - first color (RED)
        // 2 - second color (BLUE)
        vector<int> colors(this->nv, 0); // All vertex start with no color
        // the source vertex will start with color red, meaning that it's part of RED set
        colors[0] = 1;
        // Queue used to perform BFS transverse
        queue<int>q;
        q.push(0);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            // Finding all non colored adjacent vertexes of u
            for (int i = 0; i < (int)g[u].size(); i++) {
                // If there's a self loop, return false
                if(g[u][i] == u)
                    return false; // Cannot have self loop
                if(colors[g[u][i]] == 0) { // if there's no color yet
                    colors[g[u][i]] = colors[u] + 1;
                    q.push(g[u][i]);
                } else if (colors[g[u][i]] == colors[u]){ // otherwise, if there's color, then: check if the color of u is the same as the color of its adjacent
                    return false;
                }
            }
        }
        // if it gets here, then, it's bipartite
        return true;
    }
};
int main()
{
    int n, m, u, v;
    cin >> n >> m;
    Graph g(n);
    while(m--) {
        cin >> u >> v;
        u--; v--;
        g.addEdge(u,v);
    }
    cout << g.isBipartite() << endl;
    return 0;
}
