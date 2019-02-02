#include <iostream>
#include <list>
#include <queue>
#define INFINITY 10000000

using namespace std;

/*
    Dijkstra (Minimum paths from point A to B) is a greedy algorithm.

    The Dijkstra's algorithm will keep running until all of the reachable vertexes in a graph
    have been visited, which means that we could run Dijkstra's algorithm, find the shortest path
    between any two reachable node, and then save the result somewhere. Once we run Dijkstra’s algorithm just once,
    we can look up our results from our algorithm again and again without having to actually run the algorithm itself!
    Only if we update the graph we have to rerun the algorithm.

    Rules for running Dijkstra Algorithm:
    1 ->> From the starting node, visit the vertex with the smallest known distance/cost
    2 ->> Once we've moved to the smallest cost vertex, check each of its neighboring nodes.
    3 ->> Calculate the distance/cost for the neighboring nodes by summing the cost of the edges
    leading from the start vertex.
    4 ->> If the distance/cost to a vertex we are checking is less than a know distance, update the shortest
    distance/cost for that vertex.
    Dijkstra's algorithm is an algorithm for finding
    the shortest paths between nodes in a graph, which
    may represent, for example, road networks.

    Since we don't not know if there's a path from any node to another, we need to specify that the shortest
    distance from any node to another is infinity. However, the node that we starting our algorithm has a distance
    to itself as 0.

    Example (undirected graph):
    a -> (7,b) -> (3,c)
    b -> (7,a) -> (1,c) -> (2,d) -> (6,e)
    c -> (3,a) -> (1,b) -> (2,d)
    d -> (2,b) -> (2,c) -> (4,e)
    e -> (6,b) -> (4,d)

    We have a table, that will store previous vertex to one node (to keep track of where the node came from to find its path)
    and we'll have a part that stores the shortest path from one node to this one
    starting from a:

    v - shortest path - previous
    a       0             none
    b    infinity         none
    c    infinity         none
    d    infinity         none
    e    infinity         none

    checking neighborings of a: which is b and c, and some their cost and check is the result is less than the one previous computed

    a -> c: 0 + 3 = 3, is 3 < infinity? yes
    a -> b: 0 + 7 = 7, is 7 < infinity? yes
    v - shortest path - previous
    a       0             none
    b       7              a
    c       3              a
    d    infinity         none
    e    infinity         none

    Since we need to start from the smallest cost node, c is going to be the next vertex to be checked
    for c, we have tree vertexes, a, b and d, but a was already visited, so check b and c

    c -> b: 3 + 1 = 4, is 4 < b(7) ? yes
    c -> d: 3 + 2 = 5, is 5 < infinity ? yes
    v - shortest path - previous
    a       0             none
    b       4              c
    c       3              a
    d       5              c
    e    infinity         none

    Again, we'll look at the node with the smallest cost that hasn't been visited yet.
    a and c was already visited, so the next one with the smallest cost is b which is 4.
    for b, we have as its neighborings the vertexes a, c, d and e, but a and c was already visited, so:

    b -> d: 4 + d(2) = 6, is 6 less than 5? no
    b -> e: 4 + e(6) = 10, is 10 less than infinity? yes
    v - shortest path - previous
    a       0             none
    b       4              c
    c       3              a
    d       5              c
    e       10             b

    The next unvisited smallest vertex is d and its neighborings are: b, c and e, but b and c was already visited, so check just e
    d -> e: 5 + e(4) = 9, is 9 < 10? yes
    v - shortest path - previous
    a       0             none
    b       4              c
    c       3              a
    d       5              c
    e       9              d

    The next unvisited smallest vertex is e and its neighborings are: b, d, but b and d was already visited, so, stop algorithm.

    So although we want to find the shortest path between two node, Dijkstra's algorithm gives the shortest path from our start node to
    every other reachable node. This table allow us to look up all possible shortest path starting from node a for example
    To retrace the shortest path we can follow the previous vertex of any node.

    Dijkstra's algorithm is similar to Breadth-first search, the difference is that it can handle weighted graphs well.
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
