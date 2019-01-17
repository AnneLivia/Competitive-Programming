#include <iostream>
#include <vector>

using namespace std;

/*
    Information taken from: geeks for geeks
    Topological Sort using departure time of a vertex
    Topological sort is a linear ordering of vertexes such that
    for every directed edge u-v, vertex u comes before v in the
    ordering. This only works for DAGs (Directed acyclic graphs).
    This algorithm here uses the concept of departure of a vertex
    in a DFS.

    Arrival time: time at which a vertex was first explored in DFS
    departure time: (time when a vertex is not explored anymore)
    time at which all neighbors of a vertex was explored and it
    can do backtrack.

    To find a topological sort using departure time, just run DFS,
    for any vertex, before exploring any of its neighbors, the arrival time
    is calculated, and after exploring it, the departure time is calculated,
    only departure time is need in topological sort (the ones that were finished,
    first are going to be the last ones, and the ones that were finished last, comes
    first. after finish the DFS with the departure time calculated, print the vertexes
    in order of their decreasing departure time.
*/

class Graph {
private:
    vector<vector<int>> adj;
    vector<int>indegree;
    int nVertex;
public:
    Graph(int nVertex) {
        this->nVertex = nVertex;
        adj.assign(this->nVertex, vector<int>());
        indegree.assign(this->nVertex, 0);
    }

    void addArc(int u, int v) {
        this->adj[u].push_back(v);
        this->indegree[v]++;
    }

    void dfs(int vertex, vector<bool>&visited, vector<int>& departure, int& time) {
        visited[vertex] = true;

        for(auto v : adj[vertex]) {
            if(!visited[v])
                dfs(v, visited, departure, time);
        }

        // Store at time index, the vertex
        departure[time++] = vertex;
    }

    void topsort() {
        vector<bool> visited;
        vector<int> departure;

        visited.assign(this->nVertex, false);
        departure.assign(this->nVertex, -1);

        int time = 0;

        for (int i = 0; i < this->nVertex; i++) {
            if(!visited[i])
                dfs(i,visited,departure,time);
        }

        // Printing vertex (the ones with highest time are first)
        for(int i = this->nVertex - 1; i >= 0; i--)
            cout << departure[i] << " ";
        cout << endl;
    }
};

int main()
{
    Graph g(6);
    g.addArc(5, 2);
    g.addArc(5, 0);
    g.addArc(4, 0);
    g.addArc(4, 1);
    g.addArc(2, 3);
    g.addArc(3, 1);

    cout << "TopSort using departure time: \n";
    g.topsort();
    return 0;
}
