#include <iostream>
#include <vector>
#define INF 100000000

using namespace std;

/*
    Prim`s algorithm is another way to give us the minimum spanning tree
    It's is a greedy Algorithm, the differences between prim's and Kruskal's algorithm, are:
        - In Kruskal’s algorithm it begins with an edge, but in Prim's algorithm it start with a node.
        - In Kruskal's Algorithm select the next edge in a haphazard way but in increasing order while in
          Prim's algorithm it move from one node to another.
        - Kruskal's algorithm works on  both connected and disconnected graph while in Prim's algorithm
          restricted on connected graph.
    Prim`s algorithm is significantly faster in the limit when
    you've got a really dense graph with many more edges than
    vertexes. Kruskal performs better in typical situations
    (sparse graphs) because it uses simpler data structures.
    In Prim's algorithm at any point of time,  the set of selected edges will form a single tree.
    In Kruskal's algorithm at any point of time,  the set of selected edges need not belong to the same tree.
    But at the end we will have a single spanning tree.
    OBS (Use Prim's algorithm when you have a graph with lots of edges else use Kruskal’s algorithm.)

    Steps:
     - Create a set to keep track of the vertexes already included in the mst
     - Assign all values as key infinity, the source starts with 0
     - while the set that keep tracks of all vertexes included is not complete:
        - pick a vertex u which is not in the mst and has a minimum value
        - include it in the set
        - update the key values from all of its adjacent (relax)
*/
class Graph {
private:
    vector<vector<int> > grid;
    int nv;
public:
    Graph(int nv) : nv(nv) {
        grid.assign(nv, vector<int>(nv, 0));
    }

    void addEdge(int u, int v, int w) {
        this->grid[u][v] = w;
        this->grid[v][u] = w;
    }

    void primsAlgorithm() {
        vector<int>isMst(this->nv, 0); // Keep track of which element is in the mst
        vector<int>parent(this->nv, -1); // get its parents
        vector<int>dist(this->nv, INF);

        // Including first index to MST
        dist[0] = 0;

        for (int i = 0; i < this->nv; i++) {
            // Getting the minimum element from the array dist that is not include yet in the mst
            int value = INF, minimum = 0;
            for (int j = 0; j < this->nv; j++) {
                if(!isMst[j]  && dist[j] < value) {
                    minimum = j;
                    value = dist[j];
                }
            }

            isMst[minimum] =  true; // Now the minimum taken is part of the tree


            for (int v = 0; v < this->nv; v++) {
                if(grid[minimum][v] != 0) { // If v is adjacent of minimum
                    if(!isMst[v] && grid[minimum][v] < dist[v]) {
                        parent[v] = minimum;
                        dist[v] = grid[minimum][v];
                    }
                }
            }
        }

        for (int i = 1; i < this->nv; i++) {
            cout << parent[i] << " -> " << i << ": " << dist[i] << endl;
        }
    }
};
int main()
{
    Graph g(5);
    g.addEdge(0,1,2);
    g.addEdge(0,3,6);
    g.addEdge(1,2,3);
    g.addEdge(1,3,8);
    g.addEdge(1,4,5);
    g.addEdge(2,4,7);
    g.addEdge(3,4,9);
    g.primsAlgorithm();
    return 0;
}
