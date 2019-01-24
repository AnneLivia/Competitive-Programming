#include <iostream>
#include <vector>
#include <list>

/*
    Transpose of a directed graph G is another directed graph
    on the same set of vertices with all of the edges reversed
    compared to the orientation of the corresponding edges in G.
    That is, if G contains an edge (u, v) then the converse
    /transpose/reverse of G contains an edge (v, u) and vice versa.
*/

using namespace std;

class Graph {
private:
    list<int> *adj;
    int n_vertex;
public:
    Graph(int n_vertex) : n_vertex(n_vertex) {
        this->adj = new list<int>[this->n_vertex];
    }

    void createEdge(int u, int v) {
        this->adj[u].push_back(v);
    }

    void showEdges() {
        for (int u = 0; u < n_vertex; u++) {
            cout << (char)(u + 'A') << " -> ";
            int first = 0;
            for (auto v : this->adj[u]) {
                if(first) {
                    cout << ", ";
                }
                cout << (char) (v + 'A');
                first = 1;
            }
            cout << endl;
        }
    }

    // Transpose or reversed or converse of a graph is done by inverting
    // the edge, that is, if G that contains an edge (v,u), then the reversed
    // is (u,v) and vice versa.

    Graph transposeG() {
        Graph g(this->n_vertex); // Create a new vertex that is going to receive the transpose graph
        // For all vertexes
        for (int i = 0; i < n_vertex; i++) {
            // run though all adjacent of I vertex.
            for (auto it = adj[i].begin(); it != adj[i].end(); it++) {
                // for each (i,v) create in the new graph (transpose) an edge (v,i)
                g.createEdge(*it, i); // In each adjacent of i, its adjacent now is going to point to i
            }
        }

        return g; // return transpose, reversed or converse of G graph
    }

    ~Graph() {
        delete[] adj;
    }
};

int main()
{
    Graph g(5);
    g.createEdge(0,1);
    g.createEdge(0,4);
    g.createEdge(0,3);
    g.createEdge(2,0);
    g.createEdge(3,2);
    g.createEdge(4,1);
    cout << "Original graph: \n";
    g.showEdges();
    cout << "Transpose graph: \n";
    Graph tG = g.transposeG();
    tG.showEdges();
    return 0;
}
