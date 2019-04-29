#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

/*
    A Computer Science curriculum specifies the prerequisites
    for each course as a list of courses that should be taken
    before taking this course. You would like to perform
    a consistency check of the curriculum, that is, to
    check that there are no cyclic dependencies. For this,
    you construct the following directed graph: vertices
    correspond to courses, there is a directed edge (u,v)
    is the course u should be taken before the course v.
    Then, it is enough to check whether the resulting graph
    contains a cycle.
    Task. Check whether a given directed graph with n vertices and m edges contains a cycle.
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
    bool hasCycleBFS() {
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
        if(nVertex == this->nv)
            return false;
        return true;
    }

    bool hasCycleDFS() {
        vector<int>vi(this->nv, 0), rec(this->nv, 0);
        for (int i = 0; i < this->nv; i++) {
            if(detectCycleDFS(i,vi,rec))
                return true;
        }
        return false;
    }

    bool detectCycleDFS(int v, vector<int>& vi, vector<int>& rec) {
        if(!vi[v]) {
            vi[v] = rec[v] = 1; // Marking vertex as visited
            // Checking all of its adjacent
            for (auto it = adj[v].begin(); it != adj[v].end(); it++) {
                if(rec[*it])
                    return true;
                if(!vi[*it] && detectCycleDFS(*it, vi, rec))
                    return true;
            }
        }
        rec[v] = 0;
        return false;
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
    cout << gf.hasCycleBFS() << endl;
    return 0;
}
