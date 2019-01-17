#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
    Kahn's algorithm for Topological Sorting
    information taken from: geeks for geeks
    Topological sorting for Directed Acyclic Graph (DAG)
    is a linear ordering of vertexes such that for every
    directed edge u-v, vertex u comes before v in the ordering.
    Topological Sorting for a graph is not possible if the
    graph is not a DAG, which means that contains cycle.


    Steps to construct the algorithm:
    1: Compute all in-degree (number of incoming edges) for
    each of the vertex present in the DAG and initialize the count
    of visited nodes as 0.
    2: Pick all the vertexes with in-degree (source vertex) as 0 and add
    them into a queue.
    3: Remove a vertex from the queue and then:
        1: increment count of visited nodes by 1.
        2: decrease in-degree by 1 for all its neighboring nodes
        3: if in-degree of a neighboring nodes is reduced to zero, then add it to the queue
    4: repeat step 3 until queue is empty
    5: if count of visited nodes is not equal to the number of nodes in the graph
       then the topological sort is not possible for the given graph

*/

class Graph {
private:
    vector<int>indegree;
    vector<vector<int>>adj;
    int nVertex;
public:
    Graph(int nVertex) : nVertex(nVertex) {
        adj.assign(this->nVertex, vector<int>());
        indegree.assign(this->nVertex, 0);
    }

    void createArc(int v, int w) {
        adj[v].push_back(w);
        indegree[w]++;
    }

    void topsort() {
        vector<int>top_order; // Will store vertexes in some specific topological order
        queue<int>q; // Queue to store all in-degree vertexes
        int number_of_vertex = 0; // Will mark how many and in which position store a vertex in the list

        for (int i = 0; i < this->nVertex; i++) {
            if(indegree[i] == 0)
                q.push(i); // Inserting all 0 in-degree vertexes in the queue
        }

        while(!q.empty()) {
            int v = q.front(); // Getting first vertex with in-degree from queue
            top_order.push_back(v); // Inserting it in the top_order vector
            q.pop();
            // Iterating through all v neighboring nodes
            for (int i = 0; i < (int)adj[v].size(); i++) {
                indegree[adj[v][i]]--; // Decreasing from its neighboring the in-degree number
                if(indegree[adj[v][i]] == 0) // if it has become a source node, then add it to the queue
                    q.push(adj[v][i]);
            }

            number_of_vertex++;
        }


        // If the number of visited nodes is not equal to the number of nodes in the graph
        // the topological cannot be done, it is a graph with cycle.
        if(number_of_vertex != this->nVertex) {
            cout << "There's a cycle\n";
        } else {
            for(int i = 0; i < this->nVertex; i++)
                cout << top_order[i] << " ";
            cout << endl;
        }
    }
};

int main()
{
    Graph g(4);
    g.createArc(0,2);
    g.createArc(0,3);
    g.createArc(3,1);
    g.createArc(1,2);

    g.topsort();
    return 0;
}
