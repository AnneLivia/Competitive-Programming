#include <iostream>
#include <list>
#include <set>
#include <vector>
#include <limits>
#include <stack>

using namespace std;

/*
    Time Complexity : Set in C++ are typically implemented
    using Self-balancing binary search trees. Therefore,
    time complexity of set operations like insert, delete
    is logarithmic and time complexity of above solution is O(E Log V)).
    Steps taken from Geeks for Geeks:
    1) Initialize distances of all vertexes as infinite.
    2) Create an empty set.  Every item of set is a pair
      (weight, vertex). Weight (or distance) is used as first
      item  of pair as first item is by default
      used to compare two pairs.

    3) Insert source vertex into the set and make its
       distance as 0.

    4) While Set doesn't become empty, do following
        a) Extract minimum distance vertex from Set.
           Let the extracted vertex be u.
        b) Loop through all adjacent of u and do
           following for every vertex v.
               If there is a shorter path to v through u.
               If dist[v] > dist[u] + weight(u, v)
                   (i) Update distance of v, i.e., do
                        dist[v] = dist[u] + weight(u, v)
                   (i) If v is in set, update its distance
                       in set by removing it first, then
                       inserting with new distance
                   (ii) If v is not in set, then insert
                        it in set with new distance
    5) Print distance array dist[] to print all shortest
       paths.
    OBS: it can be used another array to store the parents of each vertex, to keep track of the path
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

    void addArc(int u, int v, int w) {
        this->adj[u].push_back({v,w});
    }

    void dijkstra(int source) {
        vector<int>visited(this->nv, 0);
        // Vector that will store distances of source to each one the nodes reachable
        vector<int>dist(this->nv, INT_MAX);
        // Vector that will keep track of the shortest path from the source to each reachable node
        vector<int>parent(this->nv, -1);
        // set to keep track of nodes that are being processed
        set<pair<int,int> > processing;

        // At the beginning only the shortest distance of the source is known which is 0
        processing.insert({0, source});
        dist[source] = 0;

        // While the set is not empty the loop will keep running until all reachable from source is processed
        while(!processing.empty()) {
            // Get minimum distance among all distances from vertex that were not processed yet.
            // Each set store a pair of integers, where the first one is the weight and the second one is the vertex
            pair<int,int> u = *(processing.begin()); // Begin return an iterator, when we dereference it, we get the value
            processing.erase(processing.begin()); // removing first element from processing list
            // Run through all of its adjacent
            // mark as visited, even though its adjacent can have an edge to u
            // its shortest path is already set, since its the minimum value among all checked.
            // So its distance cannot change since the graph doesn't accept negative weight
            visited[u.second] = 1;

            list<pair<int,int> >::iterator it;
            for (it = adj[u.second].begin(); it != adj[u.second].end(); it++) {
                // If its adjacent was not computed yet, i.e. if it has not it's define shortest path, then:
                if(!visited[(*it).first]) {
                    // weight from u to current adjacent ((*it).second) + the already calculated distance of u.
                    // U it's already the minimum, so it's for sure the shortest path.
                    int cost = (*it).second + dist[u.second];
                    // If the cost is less than the distance of its adjacent, then:
                    if(cost < dist[(*it).first]) {
                        // If the dist of its adjacent is equal to Infinity, then, it wasn't added to the set yet
                        if(dist[(*it).first] == INT_MAX) {
                            processing.insert({cost, (*it).first});
                        } else {
                            // The vertex was already added, so the cost updated and we must delete the
                            // pair from set and add it again, it finds where the element is and remove it
                            processing.erase(processing.find({dist[(*it).first], (*it).first}));
                            // And add it again
                            processing.insert({cost, (*it).first});
                        }
                        // Now update dist with the relaxed value and parent with its parent vertex to get the path
                        dist[(*it).first] = cost;
                        parent[(*it).first] = u.second;
                    }
                }
            }
        }
        cout << "From " << source << endl;
        for (int i = 0; i < this->nv; i++) {
            cout << i << ": " << dist[i] << endl;
            stack<int>s;

            int aux = i;
            while(aux != -1) {
                s.push(aux);
                aux = parent[aux];
            }
            cout << "Path: ";
            if(s.empty())
                cout << "null";
            while(!s.empty()) {
                cout << s.top() << " ";
                s.pop();
            }
            cout << endl;
        }
    }

    ~Graph() {
        delete[] adj;
    }
};
int main()
{
    Graph g(9);
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
    g.dijkstra(0);
    return 0;
}
