#include <iostream>
#include <queue>
#include <list>
#include <stack>
#include <vector>
#define INF 100000000

using namespace std;
/*
    The single source shortest path of a graph can be found very fast
    in a DAG because it can be ordered in a topological order via topSort and
    processed sequentially.
    To calculate shortest path on DAGS we use the topological sorting.
    The complexity for the calculation is O(V+E).
    Steps:
        - Initialize distances of all vertexes as infinite, but the source with distance as 0
        - Then, find the topological sort of the graph
        - Then process all vertexes one by one in topological order.
        - To each one of them, update the distances of its adjacent using distance of the current one (Relaxing process).

*/

class Graph {
private:
    list<pair<int,int> > *adj;
    int nv;
public:
    Graph(int nv) : nv(nv) {
        this->adj = new list<pair<int, int> >[this->nv];
    }

    void addEdge(int u, int v, int w) {
        this->adj[u].push_back({v,w});
    }

    // Topological sorting using Kahn's algorithm
    vector<int> topSort() {
        // Vector to store the in degree number of each vertex
        vector<int>inDegree(this->nv, 0);
        // Vector to store vertex in topological order
        vector<int>topOrdered;

        // Looping through each vertex to compute in degree
        for (int i = 0; i < this->nv; i++) {
            for(auto it : adj[i]) {
                inDegree[it.first]++;
            }
        }

        // Inserting in the queue all source vertexes (In degree equals to 0)
        queue<int>q;
        for (int i = 0; i < this->nv; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }

        // While number of in degree (source vertex) is different of 0
        while(!q.empty()) {
            // Get the first source vertex
            int u = q.front();
            // Remove it from the queue, to mark that this vertex as already processed ("remove from graph")
            q.pop();
            // Insert it into the vector that keep track of the topological order
            topOrdered.push_back(u);
            // Run through all of u adjacent
            for(auto it : adj[u]) {
                // Since u was removed from graph, decrement by one all of the in degree of its adjacent
                inDegree[it.first]--;
                // If its adjacent appears with 0 in degree (if it becomes a source vertex), add it to the queue
                if(inDegree[it.first] == 0)
                    q.push(it.first);
            }
        }
        // if the number of vertex add to the topOrdered vector is different from the number of vertex of the graph
        // it means that not all the vertex was processed, then there's a cycle, because it could not find another source vertex.
        if(topOrdered.size() != this->nv) {
            throw "Cannot perform topological sort, it has cycle";
        }
        // Otherwise, return the vector of the vertex sorted in topological order
        return topOrdered;
    }

    // Calculating shortest Path
    void shortestPath(int start, int to) {
        // Get topological order
        vector<int>topOrder = this->topSort();
        // Create a vector of dist to keep track of the cost
        vector<int>dist(this->nv, INF);
        // Vector to keep track of each vertex's predecessor
        vector<int>pre(this->nv, -1);

        // Start vertex starts with distance as 0
        dist[start] = 0;

        // Run through each vertex in top order to process each one of them
        for (int i = 0; i < (int)topOrder.size(); i++) {
            // if the distance is different of INF, then it will be processed,
            // Since at the beginning the vertex from where we start has and is the only one with
            // distance as 0, then, we will get this one first and check its adjacent
            if(dist[topOrder[i]] != INF) {
                // Check each adjacent of this topOrder[i] vertex
                for(auto it : adj[topOrder[i]]) {
                    // Calculating the cost which is the sum of the weight of this topOrder[i] vertex
                    // plus the weight of the current topOrder[i] adjacent
                    int cost = dist[topOrder[i]] + it.second;
                    // If the cost is less than the current dist of the processed adjacent, then relax it
                    if(cost < dist[it.first]) {
                        dist[it.first] = cost;
                        // Save its predecessor
                        pre[it.first] = topOrder[i];
                    }
                }
            }
        }
        for (int i = 0; i < this->nv; i++) {
            cout << i << " -> " << dist[i] << endl;
        }
        cout << "From " << (char)(start + 'A') << " to " << (char)(to + 'A') << ":\n";
        stack<int>path;
        path.push(to);
        int aux = pre[to];
        while(aux != -1) {
            path.push(aux);
            aux = pre[aux];
        }
        while(!path.empty()) {
            cout << (char)(path.top() + 'A')<< " ";
            path.pop();
        }
        cout << endl;
    }

    ~Graph() {
        delete[] adj;
    }
};
int main()
{
    Graph g(8);
    g.addEdge(0, 1, 3);
    g.addEdge(0, 2, 6);
    g.addEdge(1, 3, 4);
    g.addEdge(1, 4, 11);
    g.addEdge(1, 2, 4);
    g.addEdge(2, 4, 8);
    g.addEdge(2, 6, 11);
    g.addEdge(3, 4, -4);
    g.addEdge(3, 5, 5);
    g.addEdge(3, 6, 2);
    g.addEdge(4, 7, 9);
    g.addEdge(5, 7, 1);
    g.addEdge(6, 7, 2);
    g.shortestPath(0, 7);
    return 0;
}
