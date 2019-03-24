#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdlib>
#define INF 10000000

using namespace std;

class Graph {
private:
    // Edge list
    vector<vector<pair<int, int> > > g;
    int nv, directed;
public:
    Graph(int nv, int directed) : nv(nv), directed(directed) {
        this->g.assign(nv, vector<pair<int, int> >());
    }

    void addEdge(int u, int v, int d) {
        this->g[u].push_back({v, d});
    }

     // method to show graph
    void showGraph() {
        for (int i = 0; i < this->nv; i++) {
            cout << i << " -> ";
            for(int j = 0; j < (int)g[i].size(); j++) {
                if(j != 0)
                    cout << " -> ";
                cout << "("<<g[i][j].first << "," << g[i][j].second << ")";
            }
            cout << endl;
        }
    }

    // return reversed graph to be used in the backward search
    Graph getReversedGraph() {
        Graph rGraph(this->nv, this->directed);
        for (int i = 0; i < this->nv; i++) {
            // inverting edges, child start to point to parent node
            for (int j = 0; j < (int)g[i].size(); j++) {
                rGraph.addEdge(g[i][j].first, i, g[i][j].second);
            }
        }
        return rGraph;
    }

    void dijkstra(priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > >& pq,
    vector<int>& dist, vector<int>& path, vector<bool>& finished) {
        // extract minimum
        int v = pq.top().second;
        int d = pq.top().first;
        // remove from priority queue
        pq.pop();

        // assure that v vertex has already been proceeded
        finished[v] = true;

        // run though vertexes connected to minimum vertex
        for (int i = 0; i < (int)this->g[v].size(); i++) {
            // get adjacent vertex and weight
            int u = g[v][i].first;
            int w = g[v][i].second;
            // relaxation step, weight of current adjacent + the cost of V
            if(w + d < dist[u]) {
                // if smaller than distance saved at dist[u], update distance
                dist[u] = w + d;
                // save its predecessor
                path[u] = v;
                // insert in the priority queue with the updated distance
                pq.push({dist[u], u});
            }
        }
    }

    // method to show the shortest path
    void showPath(int& s, int& i, int& d, vector<int>& pathSource, vector<int>& pathDest) {
        // create vector to store full path: from V to t and from T to U
        vector<int>fullPath;
        int aux = i;
        while(aux != -1) {
            fullPath.push_back(aux);
            aux = pathSource[aux];
        }
        // since the first part of the path goes backwards, from T to S, we need to reverse it, so that it turns to S to T
        reverse(fullPath.begin(), fullPath.end());
        aux = i;
        // now the direction is from T to D, there's no need to reverse here, and it will be added on the end of the vector
        while(aux != d) {
            aux = pathDest[aux];
            fullPath.push_back(aux);
        }
        // now show path
        for (int i = 0; i < (int)fullPath.size(); i++) {
            if(i != 0)
                cout << " ";
            cout << fullPath[i];
        }
        cout << endl;
    }


    int getIntersectedVertex(vector<int>& distSource, vector<int>& distDest, vector<bool>& finishedSource, vector<bool>& finishedDest) {
        int shortestPath = INF + INF, intersectedNode = -1;
        // run through each one of the vertexes
        for (int i = 0; i < this->nv; i++) {
            // check if vertex I was processed in both PQ
            // and if it was removed from priority queue of both vertexes (source and destination), that is, if the node is true on the finished vectors
            if(distSource[i] != INF && distDest[i] != INF && finishedSource[i]) {
                // verify shortest path using I intersected node
                int dist = distSource[i] + distDest[i];
                if(dist < shortestPath) {
                    shortestPath = dist;
                    intersectedNode = i;
                }
            }
        }

        for (int i = 0; i < this->nv; i++) {
            // check if vertex I was processed in both PQ
            // and if it was removed from priority queue of both vertexes (source and destination), that is, if the node is true on the finished vectors
            if(distSource[i] != INF && distDest[i] != INF && finishedDest[i]) {
                // verify shortest path using I intersected node
                int dist = distSource[i] + distDest[i];
                if(dist < shortestPath) {
                    shortestPath = dist;
                    intersectedNode = i;
                }
            }
        }
        return intersectedNode; // if -1, error
    }

    bool bidirectional_dijkstra(int source, int destination) {
        // create vectors to store distances of graph
        vector<int>distSource(this->nv, INF);
        vector<int>distDest(this->nv, INF);

        // vectors to keep track of which vertexes were already processed and established its shortest path
        vector<bool>finishedSource(this->nv, false);
        vector<bool>finishedDest(this->nv, false);

        // create vectors to store path of shortest path from source to destination
        vector<int>pathSource(this->nv, -1);
        vector<int>pathDest(this->nv, -1);

        //priority queue for both source and destination vertex
        priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pqSource;
        priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pqDest;

        // dist of source to source and destination to destination is 0
        distSource[source] = 0;
        distDest[destination] = 0;

        // insert them on priority queue
        pqSource.push({distSource[source], source});
        pqDest.push({distDest[destination], destination});

        // get reversed graph to perform Dijkstra backwards
        Graph rGraph = this->getReversedGraph();

        // while priority queue of both vertexes is not empty
        while((!pqSource.empty()) && !pqDest.empty()) {
            // run Dijkstra for source with the original graph represented by *this and reversed graph
            dijkstra(pqSource, distSource, pathSource, finishedSource);
            rGraph.dijkstra(pqDest, distDest, pathDest, finishedDest);

            // verify if both of them intersects in a specific node which marks the shortest path
            // the algorithm stops when either, a node was proceeded in both priority queues and they were extracted from them
            // which means that it was already found a shortest path from v to T, and from u to T, so V -> T -> U exists and is the shortest path

            int intersection = this->getIntersectedVertex(distSource, distDest, finishedSource, finishedDest);

            // if is not -1, it was found an intersected node
            if(intersection >= 0) {
                cout << "Intersection occurred in vertex " << intersection << endl;
                cout << "Path: ";
                this->showPath(source, intersection, destination, pathSource, pathDest);
                cout << "Distance is: " << distSource[intersection] + distDest[intersection] << endl;
                return true;
            }
        }

        return false; // if it get here, there's any path from source to destination vertexes
    }
};

int main()
{
    Graph g(9, 1);
    int nv, n, u, v, w;
    /*
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
    */
    while(cin >> nv >> n && nv != 0 && n != 0) {
        Graph g(nv, 0);
        while(n--) {
            cin >> u >> v >> w;
            --u; --v;
            g.addEdge(u, v, w);
        }
        int source = 0, destination = 0;
        while(cin >> source >> destination && source != -1 && destination != -1) {
            cout << "Vertex: \n";
            --source; --destination;
            if(!g.bidirectional_dijkstra(source, destination)) {
                cout << "There's any path from " << source << " to " << destination << endl;
            }
            system("pause");
            system("cls");
            g.showGraph();
        }
        cout << "Finished. Insert new vertexes.\n";
    }
    return 0;
}
