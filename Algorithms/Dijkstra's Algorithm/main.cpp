#include <iostream>
#include <list>
#include <queue>
#define INFINITY 10000000

using namespace std;

/*
    Dijkstra's algorithm is an algorithm for finding
    the shortest paths between nodes in a graph, which
    may represent, for example, road networks.
    Dijkstra (Minimum paths from point A to B) is a greedy algorithm.

    Example:
    A driver wants to know the minimum path (more shorter) in between city A and city B. Given a map from the State where those city are, with the distances in each adjacent intersection path
    how to get the minimum in between the cities?

    In this case we can model a driveway map as a graph in which the vertexes are
    the intersections, edges are the segments of the road in intersections and the
    weight of each edge are the distance in intersections.

    Dijkstra is an algorithm that finds the minimum path in between two vertex in a graph, when all of the arcs has length no-negative.

    Dijkstra algorithm:
    procedure Dijkstra (graph, root):
        for v = 0 to graph.nVertex - 1 do:
            p[v] = infinity;
            pre[v] = -1;
        p[root] = 0;
        build heap in vector A
        S = empty
        while heap > 1 do:
            u = takeMinOut(A);
            S = S + u;
            for v in AdjacentList[u] do:
                if p[v] > p[u] + vertex weight (u,v)
                then p[v] = p[u] + weight vertex (u,v)
                    pre[v] = u


*/

class Graph {
private:
    int n_vertex; // Number of vertex
    list<pair<int,int>> *adj; // Adjacent list graph with pair to identify which vertex is connect to which one with weight x
    // Example: adj[0].push_back(make_pair(1,X)); // vertex 0 is connected with vertex 1 with weight X
public:
    Graph(int n_vertex) : n_vertex(n_vertex) {
        // Creating a list
        this->adj = new list<pair<int,int> >[this->n_vertex];
    }

    void addEdge(int v1, int v2, int weight) {
        this->adj[v1].push_back(make_pair(v2, weight));
    }

    // Dijkstra algorithm
    int dijkstra(int orig, int dest) {
        // Array of distances
        int dist[this->n_vertex];
        // Array of visited vertex, it's good to verify if a vertex wasn't expanded or in case it was already expanded, don't expand it anymore
        int visited[this->n_vertex];

        // Create the priority queue that makes minimum value as a priority
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

        // Initialize the dist and visited arrays
        for(int i = 0; i < this->n_vertex; i++) {
            dist[i] = INFINITY;
            visited[i] = false;
        }

        // The distance from orig to orig is 0
        dist[0] = 0;

        // Insert in the queue
        pq.push(make_pair(dist[orig], orig));

        // loop
        while(!pq.empty()) {
            pair<int,int> p = pq.top(); // get the top of the queue to check which is going to be expanded
            int u = p.second; // get the vertex
            pq.pop(); // Remove from the queue

            // Verify if the vertex was not expanded yet
            if(visited[u] == false) {
                // mark as visited
                visited[u] = true;

                list<pair<int, int> >::iterator it; // to transverse list

                // transverse the vertexes v adjacent of u
                for(it = adj[u].begin(); it != adj[u].end(); it++) {
                    // Get the adj and the weight of the edge
                    int v = it->first;
                    int w = it->second;

                    // Relax (u, v)

                    if(dist[v] > (dist[u] + w)) {
                        // update dist v
                        dist[v] = dist[u] + w;
                        pq.push(make_pair(dist[v], v));
                    }
                }
            }
        }
        // return the minimum distance
        return dist[dest];
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0,1,4);
    g.addEdge(0,2,2);
    g.addEdge(0,3,5);
    g.addEdge(2,1,1);
    g.addEdge(2,3,2);
    g.addEdge(2,4,1);
    g.addEdge(1,4,1);
    g.addEdge(3,4,1);

    cout << g.dijkstra(0,4) << endl;
    return 0;
}
