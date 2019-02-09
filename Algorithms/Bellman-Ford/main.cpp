#include <iostream>
#include <queue>
#include <list>
#include <stack>
#include <vector>
#define INF 100000000

using namespace std;

/*
    Information taken from Geeks for Geeks:
    Bellman-Ford is an algorithm to find the shortest path from one start vertex
    to each reachable ones, and, on the contrary of Dijkstra's algorithm which also
    finds the shortest path from one node to each reachable ones, but works only with
    positive weight, this one works also with negative. It's complexity is O(VE) which is
    than Dijkstra, that when use Priority Queue its complexity is O(E log V), or (V log V)
    if is a Fibonacci Heap.
    In Bellman Ford - Shortest distance to all vertexes from source. If there is a negative
    weight cycle, then shortest distances are not calculated, negative weight cycle is reported.
    Steps:
        - Initialize an array of size V, of distance from source to all other vertex as Infinity,
        except to itself which is 0
        - Do the following V - 1 times, where v is the number of vertexes.
            - For each Edge u - v
                (Relaxation time)
                if dist[v] > dist[u] + weight of edge u-v, then update dist[v]
                    dist[v] = dist[u] + weight of edge u-v
        - Reports if there's a negative weight cycle in graph. Do following for each edge u-v:
            - If dist[v] > dist[u] + weight of edge u-v, then Graph contains negative cycle.
            Explanation of step 3: The idea of step 3 is, step 2 guarantees shortest distances
            if graph doesn't contain negative weight cycle. If we iterate through all edges one
            more time and get a shorter path for any vertex, then there is a negative weight cycle

    We don't have a shortest path when we have a negative cycle, because, every time we go around the cycle
    we get a shorter path, so to find a shortest path we would just go around forever. Because of that, we can
    convert the value in it to negative infinity since it can goes around the cycle as many times as it wants before
    goes to the destination.
*/

class Graph {
private:
    vector<vector<pair<int,int> > > adj;
    int nv;
public:
    Graph(int nv) : nv(nv) {
        adj.assign(nv, vector<pair<int,int> >());
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v,w});
    }

    void bellmanFord(int source) {
        // Create an array to store distance from source to each other reachable vertex
        vector<int>distance(this->nv, INF);
        distance[source] = 0; // Only distance from the source to itself is known which is 0

        // It will be done NV - 1 operation, where NV is the number of vertexes
        for (int i = 0; i < this->nv - 1; i++) {
            // Throughout this loop, it will be checked if a distance is less than the current one
            for (int u = 0; u < this->nv; u++) { // All vertexes
                for (int k = 0; k < (int) this->adj[u].size(); k++) { // All adjacent
                    // If the distance is different of INF, it means that the path to the current k was already founded being it minimum or not
                    int v = this->adj[u][k].first;
                    int w = this->adj[u][k].second;

                    if(distance[u] != INF) {
                        // Relax it if necessary (similar to Dijkstra here)
                        distance[v] = min(distance[v], distance[u] + w);
                    }
                }
            }
        }

        // When finish, run one more loop to check if there's a negative cycle, if found
        // one more shortest path, the graph contains.
        for (int i = 0; i < this->nv; i++) { // all vertexes
            for (int j = 0; j < (int)this->adj[i].size(); j++) { // all adjacent
                int v = adj[i][j].first;
                int w = adj[i][j].second;
                if(distance[i] != INF && distance[v] > distance[i] + w)
                    cout << "Contains negative cycle\n";
            }
        }

        for (int i = 0; i < this->nv; i++) {
            cout << i << " -> " << distance[i] << endl;
        }
    }
};


// Bellman ford implementation using list of adjacency
void bellmanFordListOfEdges(int source, int nv, const vector<pair<int, pair<int,int> > >& gra) {
    int nE = (int)gra.size();
    vector<int>distance(nv, INF);
    distance[source] = 0;
    // Running number of vertex minus 1 times
    for (int i = 0; i < nv - 1; i++) {
        // running through each edge
        for (int j = 0; j < nE; j++) {
            // u -> v (w)
            int u = gra[j].first;
            int v = gra[j].second.first;
            int w = gra[j].second.second;
            // If distance was already found
            if(distance[u] != INF) {
                // Relaxation step
                // distance[v] = min(distance[v], distance[u] + w);
                if(distance[v] > distance[u] + w) {
                    distance[v] = distance[u] + w;
                }
            }
        }
    }

    // Run this algorithm one more time to check if there's a negative cycle
    for (int i = 0; i < nE; i++) {
        // u -> v (w)
        int u = gra[i].first;
        int v = gra[i].second.first;
        int w = gra[i].second.second;
        if(distance[v] > w + distance[u]) {
            cout << "There's a negative cycle\n";
        }
    }

    for (int i = 0; i < nv; i++) {
        cout << i << " -> " << distance[i] << endl;
    }
}

int main()
{
    Graph g(5);
    cout << "BellmanFord with Adjacent List:\n";
    g.addEdge(0,1,-1);
    g.addEdge(0,2,4);
    g.addEdge(1,2,3);
    g.addEdge(1,3,2);
    g.addEdge(1,4,2);
    g.addEdge(3,2,5);
    g.addEdge(3,1,1);
    g.addEdge(4,3,-3);
    g.bellmanFord(0);
    cout << "BellmanFord with List of Edges:\n";
    int nv = 5;
    vector<pair<int, pair<int,int> > > gra = {
        {0,{1,-1}}, {0,{2,4}}, {1,{2,3}}, {1,{3,2}},
        {1,{4,2}}, {3,{2,5}}, {3,{1,1}}, {4,{3,-3}}
    };
    bellmanFordListOfEdges(0, nv, gra);
    return 0;
}
