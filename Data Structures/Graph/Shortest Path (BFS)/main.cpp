#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

/*
    For BFS:
        - Always finds the shortest path
        - in unweighted graphs, find optimal cost path;
        - in weighted graphs, not always find optimal cost.
    Retrieval:
        - BFS explores many possible path in parallel, so it's not easy to
        store a path array/list in progress.
        - In order to solve that, we can keep track of the path by storing predecessors
        for each vertex (each vertex can store a reference to a previous vertex)
    DFS uses less memory than BFS, easier to reconstruct the path source found, but BFS does
    not always find shortest path (BFS does)
*/

class Graph {
private:
    list<int> *adj;
    int nv;
public:
    Graph(int nv) : nv(nv) {
        this->adj = new list<int>[nv];
    }

    void addEdge(int u, int v) {
        this->adj[u].push_back(v);
        this->adj[v].push_back(u);
    }
    // predecessor
    void BFS(vector<int>& predecessor, vector<int>& dist, int u) {
        queue<int>q;
        q.push(u);
        dist[u] = 0;
        while(!q.empty()) {
            u = q.front();
            q.pop();
            for (auto it = adj[u].begin(); it != adj[u].end(); it++) {
                if(dist[*it] == -1) {
                    q.push(*it);
                    dist[*it] = dist[u] + 1; // Storing its distance from its previous
                    predecessor[*it] = u; // Keep track of its predecessor
                }
            }
        }
    }

    void shortestPath(int x, int y) {
        // Arrays to keep track of the distance and the previous vertex of each vertex
        vector<int>predecessor(this->nv, -1), dist(this->nv, -1);
        BFS(predecessor, dist, x); // Starting from x
        cout << "Distance from " << (char)(x + 'a') << " to " << (char)(y + 'a') << ": " << dist[y] << endl;
        cout << "Path taken: ";
        int aux = y;
        while(aux != -1) {
            cout << (char)(aux + 'a') << " ";
            aux = predecessor[aux];
        }
        cout << endl;
    }

    ~Graph() {
        delete[] adj;
    }
};
int main()
{
    Graph g(9);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(0, 4);
    g.addEdge(1, 4);
    g.addEdge(3, 7);
    g.addEdge(6, 7);
    g.addEdge(7, 4);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(7, 5);
    g.addEdge(7, 8);
    g.shortestPath(0, 8);
    return 0;
}
