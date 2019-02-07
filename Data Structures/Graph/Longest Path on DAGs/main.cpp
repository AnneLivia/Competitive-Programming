#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <stack>
#define MIN_INF -10000000
#define MAX_INF 10000000

using namespace std;

/*
    Longest Path in a Directed Acyclic Graph:
    Algorithm 1:
    The longest path problem is not as easy as the shortest path,
    because it doesn't have optimal substructure problems as does shortest path.
    Longest path is NP-hard for a general graph. But it has a linear time solution for a DAG.
    Steps:
        - Initialize all vertexes weights as minus infinite and distance to source as 0.
        - Find topological sorting of the graph.
        - One by one process all vertexes in topological order. (for every vertex, update its distance if necessary)

    Algorithm 2:
    Information taken from geeks for geeks website
    Another way to find the shortest path is by negating negate the weights of the path and find the shortest path in the graph.
    A longest path between two given vertexes s and t in a weighted graph G is the same thing as a shortest path in a graph G`
    derived from G by changing every weight to its negation. Therefore, if shortest paths can be found in G`, then longest
    paths can also be found in G.
    Example:
    v -> (u, w)
    1 -> (2, 2) -> (3,1)
    2 -> (4, 2)
    3 -> (4, 1)
    4 -> null
    If we negate all of the weights, the ones that are greater are going to be smaller:
    1 -> (2, -2) -> (3, -1)
    2 -> (4, -2)
    3 -> (4, -1)
    4 -> null
    In fact, -2 is less than -1.
    So in the example above, by applying a simple shortest path algorithm, be it the one used for find shortest path using topological order
    it will get the longest distance.

    OBS: Shortest/longest path in DAG is linear time, it's simple cause it gets the topological order and has the premise that, for u->v,
    we check vertex v, only when we finished checked vertex u
*/

class Graph {
private:
    list<pair<int,int> >*adj;
    int nv;
public:
    Graph(int nv) : nv(nv) {
        this->adj = new list<pair<int,int> >[this->nv];
    }

    void addEdge(int u, int v, int w) {
        this->adj[u].push_back(make_pair(v,w));
    }

    // Used to get the topological order of the graph using the time when a vertex finishes being checked
    void dfsTopoOrder(int v, stack<int>& topOrder, vector<bool>& vi) {
        vi[v] = true;
        for (auto it : adj[v]) {
            // If the adjacent of v is not visited yet
            if(!vi[it.first]) {
                dfsTopoOrder(it.first, topOrder, vi); // Visit it
            }
        }
        // When it gets here, it means that the vertex doesn't has any other adjacent to be checked, then
        // Push it onto the stack
        topOrder.push(v);
    }

    int longestPathUsingMININF(int orig, int dest) {
        // Used to store the top order, the first to get from the top is the last that was verified
        // So its guarantee that this vertex doesn't have any other dependency
        // according to topological order, for an edge u->v, initial[u] comes before initial[v] or post[u] > post[v]
        stack<int>topOrder;
        // Used to store the distance from the origin vertex to each one reachable from it
        // It uses a infinity number negative
        vector<int>dist(this->nv, MIN_INF);
        //used to keep track of which vertexes were already visited yet, during DFS
        vector<bool>vi(this->nv, false);
        // Loop used to get top order of all vertex, it's necessary to use a loop, because, since this is a DAG
        // Not all vertexes are connected to each other. The number of vertex is the number of strongly connected components
        // So in order to check each one of the vertex, it must be used a loop than run through each one of the vertex from the graph
        for (int i = 0; i < this->nv; i++) {
            // If the current vertex hasn't been visited, then check it and its adjacent
            if(!vi[i]) {
                dfsTopoOrder(i, topOrder, vi);
            }
        }
        // The orig starts with distance as 0
        dist[orig] = 0;
        // While the stack that stores the topological order is not empty
        while(!topOrder.empty()) {
            // Getting the top elements from the stack that means the first one or the one that comes next, when one has been removed in the topological order
            // Respecting the premise that, for u->v, initial of u is less than initial of v or post[u] > post[v], which means that in a dependency order, v depends upon u
            int u = topOrder.top();
            // Remove it from stack
            topOrder.pop();
            // Checking its adjacent if its distance is different of negative infinity
            if(dist[u] != MIN_INF) {
                // For each adjacent
                for(auto v : adj[u]) {
                    // Calculating the distance from the current vertex taken from stack to its current adjacent being checked
                    int cost = v.second + dist[u];
                    // weight from u to v + the distance already calculated stored in dist[u] (optimal substructure)
                    if(cost > dist[v.first]) {
                        // If the cost is greater than the distance so far saved in dist[v], then update distance
                        dist[v.first] = cost;
                    }
                }
            }
        }

        // Print all optimal distance from orig to each one of the reachable vertexes
        for (int i = 0; i < this->nv; i++) {
            cout << i << " -> " << dist[i] << endl;
        }

        return dist[dest];
    }

    // Finding the longest path using the method of negate the weights of the graph, in a graph
    // G when we have 2 edges, u -> v with weight 2 and another one u -> x with weight -1, here
    // the smaller one is u -> x since its weight is -1, but if we negate all vertex, we're gonna get a graph G`
    // where, -2 is the weight for u->v and 1 for u -> x, we "invert" the weights, the ones which were greater in
    // G is now smaller is G`, and vice versa.
    /*
        Steps:
        - Negate the weights of each edge of the graph
        -> Now it's similar to find the shortest path in a DAG
        - Initialize the array of distance to infinity, except the origin which is 0
        - Find topological order using any kind of algorithm that get that (Kahn's algorithm, Topological order by departure time, using DFS, etc.)
        OBS: When we consider a vertex u in topological order, it is guaranteed that we have considered every incoming edge to it.
        - For each one of the vertex in topological order, check is adjacent and do relaxation if necessary
        - Once the shortest path has been found, the longest path is going to be just the negation of it.
    */

    Graph GraphWithNegativeWeight() {
        Graph g(this->nv);
        // Running through each one of the vertexes of the graph to check each one of the edges
        for (int u = 0; u < this->nv; u++) {
            for(auto v : adj[u]) {
                // Negating each one of the weights
                g.addEdge(u, v.first, -v.second);
            }
        }

        return g;
    }

    int longestPathNegateWeight(int orig, int dest) {
        // The only different method here is to negative the weights
        Graph g = this->GraphWithNegativeWeight();
        stack<int>topOrder;
        vector<int>dist(this->nv, MAX_INF);
        vector<int>pre(this->nv, -1);
        vector<bool>vi(this->nv, 0);
        for (int i = 0; i < this->nv; i++) {
            if(!vi[i]) {
                g.dfsTopoOrder(i, topOrder, vi);
            }
        }

        dist[orig] = 0;

        while(!topOrder.empty()) {
            int u = topOrder.top();
            topOrder.pop();

            if(dist[u] != MAX_INF) {
                for(auto v : g.adj[u]) {
                    int cost = dist[u] + v.second;
                    if(cost < dist[v.first]) {
                        dist[v.first] = cost;
                    }
                }
            }
        }

        for (int i = 0; i < this->nv; i++) {
            if(dist[i] != MAX_INF)
                dist[i]*=-1;
        }

        for (int i = 0; i < this->nv; i++) {
            cout << i << " -> " << dist[i] << endl;
        }

        crawl(pre, dest);
        return dist[dest];
    }

    void crawl(vector<int>& pre, int dest) {
        stack<int>s;
        s.push(dest);
        int aux = pre[dest];
        while(aux != -1) {
            s.push(aux);
            aux = pre[aux];
        }

        while(!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }

    ~Graph() {
        delete[] adj;
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 5, 1);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
    cout << "From 1 to 5: " << g.longestPathUsingMININF(1, 5) << endl;
    cout << "From 1 to 5: " << g.longestPathNegateWeight(1, 5) << endl;
    return 0;
}
