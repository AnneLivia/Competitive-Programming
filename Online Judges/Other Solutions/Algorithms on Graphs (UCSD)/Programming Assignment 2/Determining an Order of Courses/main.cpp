#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

/*
    Now, when you are sure that there are no cyclic dependencies
    in the given CS curriculum, you would like to find an order
    of all courses that is consistent with all dependencies.
    For this, you find a topological ordering of the corresponding
    directed graph.

    Task. Compute a topological ordering of a given directed acyclic graph (DAG) with n vertices and m edges.
*/

class Graph {
private:
    list<int>*adj;
    int nv;
public:
    Graph(int nv) : nv(nv) {
        this->adj = new list<int>[nv];
    }

    void createEdge(int u, int v) {
        this->adj[u].push_back(v);
    }

    // Using Kahn's algorithm
    void topologicalUsingKahn() {
        // Calculating in-degree of each vertex
        vector<int>indegree(this->nv, 0), topOrder;
        int nVertex = 0;
        for (int i = 0; i < this->nv; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int>q;
        // Inserting all in-degrees 0 in the queue
        for (int i = 0; i < this->nv; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }

        // Now insert that in a vector and remove that from graph decreasing the in-degree of its adjacent
        while(!q.empty()) {
            int vertex = q.front();
            topOrder.push_back(vertex);
            q.pop();
            for (auto it : adj[vertex]) {
                indegree[it]--;
                if(indegree[it] == 0) // if in-degree is zero, insert it into the queue
                    q.push(it);
            }
            nVertex++;
        }

        // If the number of vertex inserting into the queue is different of the number of vertex from the graph, then there's cycle
        if(nVertex == this->nv) {
            for (int i = 0; i < this->nv; i++) {
                if(i != 0)
                    cout << " ";
                cout << topOrder[i] + 1;
            }
            cout << endl;
        }
    }

    void dfs(int v, vector<int>& vi, stack<int>& s) {
        vi[v] = true;
        for (auto it : adj[v]) {
            if(!vi[it])
                dfs(it, vi, s);
        }
        s.push(v);
    }

    // Topological order using DFS
    void topologicalUsingDFS() {
        stack<int>topOrder;
        vector<int>vi(this->nv,0);
        for (int i = 0; i < this->nv; i++) {
            if(!vi[i])
                dfs(i,vi,topOrder);
        }
        int space = 0;
        while(!topOrder.empty()) {
            if(space)
                cout << " ";
            cout << topOrder.top() + 1;
            space = 1;
            topOrder.pop();
        }
        cout << endl;
    }

    // Topological order using Departure time
    void dfsDeparture(int v, vector<int>&vi, vector<int>& dep, int& cont) {
        vi[v] = true;
        for (auto it : adj[v]) {
            if(!vi[it])
                dfsDeparture(it,vi,dep, cont);
        }
        dep[cont++] = v;
    }

    void topologicalUsingPOS() {
        vector<int>vi(this->nv, 0), dep(this->nv, -1);
        int cont = 0;
        for (int i = 0; i < this->nv; i++) {
            if(!vi[i])
                dfsDeparture(i,vi,dep,cont);
        }

        for (int i = this->nv - 1; i >= 0; i--) {
            if(i != this->nv - 1)
                cout << " ";
            cout << dep[i] + 1;
        }
        cout << endl;
    }

    ~Graph() {
        delete[] adj;
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
    gf.topologicalUsingKahn();
    return 0;
}
