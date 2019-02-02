#include <iostream>
#include <list>
#include <vector>
#include <limits>
#include <queue>

using namespace std;

/*
    We have a large number of choices to find the path from one none to another
    but with a shortest path algorithm we can find the shortest path that goes
    from one node to another, there are a plenty of algorithms that can produce a shortest path
    one of them is Dijkstra Algorithm, which finds the shortest path from one node to every other node
    and save it. This algorithm will run until all vertexes in the graph have been visited.
    this means that the shortest path between any two nodes can be saved and looked up later

    Steps:
    1) Create a vector Visited that keeps track of vertexes included in SPT, where at the beginning, this set is empty.
    2) Assign a distance value to all vertexes in the input graph.
        Initialize all distance values as INFINITE, only the source vertex is 0.
    3) While vector Visited doesn't include all vertexes
        a) Pick a vertex u which was not visited (it's not included in the tree yet)
        and has minimum distance value, at the beginning it's going to be the source vertex, since its distance to itself is 0.
        b) Include this element in the vector of visited
        c) Update distance value of all adjacent vertexes of u.
        To update the distance values, iterate through all adjacent vertexes.
        For every adjacent vertex v, if sum of distance value of u (from source) and weight of edge u-v,
        is less than the distance value of v, then update the distance value of v.
    OBS:
    - to check the path we can create a array that keeps track of the parents of each node

    Answer get from: https://stackoverflow.com/questions/13159337/why-doesnt-dijkstras-algorithm-work-for-negative-weight-edges
    - Dijkstra's algorithm doesn't work for graphs with negative weights.
      In Dijkstra's algorithm, once a vertex is marked as "closed" (and out of the open set)
      the algorithm found the shortest path to it, and will never have to develop this node
      again - it assumes the path developed to this path is the shortest.
      in each relaxation step, the algorithm assumes the "cost" to the "closed" nodes is indeed minimal,
      and thus the node that will next be selected is also minimal.
*/

class Graph {
private:
    list<pair<int,int> > * adjList;
    vector<vector<int> > adjMatrix;
    int nv;
public:
    Graph(int nv) : nv(nv) {
        this->adjList = new list<pair<int,int> >[this->nv];
        this->adjMatrix.assign(this->nv, vector<int>(this->nv, 0));
    }

    void addEdgeMatrix(int u, int v, int w) {
        this->adjMatrix[u][v] = w;
        this->adjMatrix[v][u] = w;
    }

    void addArcMatrix(int u, int v, int w) {
        this->adjMatrix[u][v] = w;
    }

    void addEdgeList(int u, int v, int w) {
        this->adjList[u].push_back({v,w});
        this->adjList[v].push_back({u,w});
    }

    void addArcList(int u, int v, int w) {
        this->adjList[u].push_back({v,w});
    }

    // Solution O(n^2) for adjacent matrix and O(E log V) for adjacent list
    int dijkstraForMatrix(int from, int to) {
        // Will keep track of all vertexes included in the SPT
        vector<int>visited(this->nv, 0);
        // Will keep track of all the distance from initial vertex to itself
        vector<int>distance(this->nv, INT_MAX);

        // Distance from the start to itself is 0
        distance[from] = 0;

        for (int i = 0; i < this->nv; i++) {
            // Getting minimum for current check
            int minimum = -1, value = INT_MAX;
            for (int j = 0; j < this->nv; j++) {
                if(!visited[j] && distance[j] < value) {
                    value = distance[j];
                    minimum = j;
                }
            }

            visited[minimum] = 1;

            // After get the minimum distance already calculated from a vertex that was not visited yet
            // Calculate distance from it to all of its adjacent and relax the distance
            for (int j = 0; j < this->nv; j++) {
                // If not visited yet and there's an edge connecting u and its adjacent
                // and sum of the distance of u and the weight of its adjacent not visited is less then the current weight
                if(distance[minimum] != INT_MAX && !visited[j] && adjMatrix[minimum][j] && distance[minimum] + adjMatrix[minimum][j] < distance[j]) {
                    distance[j] =  distance[minimum] + adjMatrix[minimum][j]; // Relax cost
                }
            }

        }
        for (int i = 0; i < this->nv; i++) {
            cout << i << " -> " << distance[i] << endl;
        }
        // Return answer
        return distance[to];
    }

    int dijkstraForList(int from, int to) {
        // Will keep track of all vertexes included in the SPT
        vector<int>visited(this->nv, 0);
        // Will keep track of all the distance from initial vertex to itself
        vector<int>distance(this->nv, INT_MAX);

        // Distance from the start to itself is 0
        distance[from] = 0;

        for (int i = 0; i < this->nv; i++) {
            int minimum = -1;
            for (int j = 0; j < this->nv; j++) {
                if(!visited[j]) {
                    if(minimum == -1 || distance[j] <= distance[minimum])
                        minimum = j;
                }
            }
            visited[minimum] = true;
            for (auto it = adjList[minimum].begin(); it != adjList[minimum].end(); it++) {
                if(!visited[(*it).first] && distance[minimum] != INT_MAX &&
                   (*it).second + distance[minimum] < distance[(*it).first]) {
                    distance[(*it).first] = (*it).second + distance[minimum];
                }
            }
        }

        for (int i = 0; i < this->nv; i++) {
            cout << i << " -> " << distance[i] << endl;
        }

        return distance[to];
    }

    ~Graph() {
        delete[] adjList;
    }
};
int main()
{
    Graph g(9);
    g.addEdgeList(0,1,4);
    g.addEdgeList(0,7,8);
    g.addEdgeList(1,7,11);
    g.addEdgeList(1,2,8);
    g.addEdgeList(7,8,7);
    g.addEdgeList(7,6,1);
    g.addEdgeList(6,8,6);
    g.addEdgeList(2,8,2);
    g.addEdgeList(2,3,7);
    g.addEdgeList(2,5,4);
    g.addEdgeList(6,5,2);
    g.addEdgeList(5,3,14);
    g.addEdgeList(3,4,9);
    g.addEdgeList(5,4,10);
    g.dijkstraForList(0, 8);
    return 0;
}
