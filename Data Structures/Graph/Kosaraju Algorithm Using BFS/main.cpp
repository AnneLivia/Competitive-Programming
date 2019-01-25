#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

/*
    Checking if a graph is strongly connected.
    Kosaraju's Algorithm using BFS follows the same principle as the one using DFS
    Steps of the algorithm taken from Geeks for geeks:
    1 - Initialize all vertices as not visited
    2 - Do a BFS transversal of graph starting from any arbitrary vertex v. IF BFS
    doesn't visit all vertexes, then return false.
    3 - Reverse all edges of find the reverse of the graph
    4 - Mark all vertexes as not visited in the reversed graph
    5 - Do a BFS of the reversed graph starting from the same v (same in the step 2).
    If BFS doesn't visit all vertexes, the return false.
    Otherwise, return true;

    The idea is that if in the original graph I can achieve all node starting from V,
    then, if I get the reversed graph, I can achieve all nodes v from all nodes.
    If all vertexes are reachable starting from v in the reversed graph, then all vertex
    can reach v in the original graph.
*/

class Graph {
private:
    list<int> *adj;
    int nv;
public:
    Graph(int nv) : nv(nv) {
        this->adj = new list<int>[nv];
    }

    void createArc(int u, int v) {
        this->adj[u].push_back(v);
    }

    bool BFS(int v) {
        vector<int>visited(this->nv, 0);
        queue<int>q;
        q.push(v);
        int reachable = 0;
        while(!q.empty()) {
            reachable++;
            v = q.front();
            q.pop();
            if(!visited[v]) {
                visited[v] = true;
            }
            for (auto it : adj[v]) {
                if(!visited[it])
                    q.push(it);
            }
        }
        if(reachable != this->nv) // if the BFS hasn't visited all vertexes, then it is not strongly connected
            return false;
        return true;
    }

    Graph transpose() {
        Graph tr(this->nv);
        for (int i = 0; i < this->nv; i++) {
            for(auto it : adj[i]) {
                tr.createArc(it, i);
            }
        }
        return tr;
    }

    void kosarajuUsingBFS() {
        // Doing BFS passing a arbitrary vertex
        // Doing BFS in the reversed and the original
        // from the same vertex "0"
        Graph reversed = this->transpose();
        if(BFS(0) && reversed.BFS(0)) {
            cout << "Strongly connected\n";
        } else {
            cout << "Not Strongly Connected\n";
        }
    }

    ~Graph() {
        delete[] adj;
    }
};


int main()
{
    Graph gr(5);
    gr.createArc(0,1);
    gr.createArc(1,2);
    gr.createArc(2,4);
    gr.createArc(2,3);
    gr.createArc(3,0);
    gr.createArc(4,2);
    gr.kosarajuUsingBFS();
    return 0;
}
