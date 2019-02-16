#include <iostream>
#include <list>
#include <vector>
#include <queue>
#define INF 100000000
using namespace std;

/*
    Information taken from geeks for geeks website:
    Prim`s algorithm is a minimum spanning tree algorithm
    that takes a graph as input and finds the subset of the
    edges of that graph which:
        - Form a tree that include every vertex
        - has the minimum sum of weights among all the trees that can
        be formed from the graph
    It falls under a class of algorithms called greedy algorithms
    which find the local optimum in the hopes of finding a global
    optimum.
    We start from one vertex and keep adding edges with the lowest
    weight until we we reach our goal.

    The steps for implementing Prim`s algorithm are as follows:
    - Initialize keys of all vertexes as infinite and
        parent of every vertex as -1.
    - Create an empty priority_queue in which every item is (weight, vertex).
    - Use an array to keep track of which vertex is part of mst or not.
      This array is required to make sure that an already
      considered vertex is not included in priority queue again.
    OBS: In Dijkstra's algorithm, we didn't need this array as
       distances always increase. We require this array here
       because key value of a processed vertex may decrease
       if not checked.
    - Insert source vertex into pq and make its key as 0.
    - While pq is not empty:
        -Extract minimum key vertex from pq.
        Let the extracted vertex be u.
        - Include u in MST using inMST[u] = true.
        - Loop through all adjacent of u and do
          following for every vertex v.
        - // If weight of edge (u,v) is smaller than
          // key of v and v is not already in MST
        If inMST[v] = false && key[v] > weight(u, v)
        (i) Update key of v, i.e., do
            key[v] = weight(u, v)
        (ii) Insert v into the pq
        (iv) parent[v] = u
    - Print MST edges using parent array.
*/

class Graph {
private:
    list<pair<int,int> > *adj;
    int nv;
public:
    Graph(int nv) : nv(nv) {
        this->adj = new list<pair<int,int> >[this->nv];
    }

    void addEdge(int u, int v, int w) {
        this->adj[u].push_back({v,w});
        this->adj[v].push_back({u,w});
    }

    void primsAlgorithm() {
        priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
        int src = 0;
        // Stores the weight values
        vector<int>weight(this->nv, INF);
        // Store parent
        vector<int>parent(this->nv, -1);
        // Keep track of which vertex is already part of MST
        vector<bool>isInMST(this->nv, false);

        pq.push({0,src});
        weight[src] = 0;

        while(!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            isInMST[u] = true;

            for(auto i : adj[u]) {
                int v = i.first;
                int w = i.second;

                if(!isInMST[v] && weight[v] > w) {
                    weight[v] = w;
                    pq.push({w,v});
                    parent[v] = u;
                }
            }
        }

        for (int i = 1; i < this->nv; i++) {
            cout << parent[i] << " -> " << i << endl;
        }
    }

    ~Graph() {
        delete[] adj;
    }
};
int main()
{
    // create the graph given in above fugure
    int V = 9;
    Graph g(V);

    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.primsAlgorithm();
    return 0;
}
