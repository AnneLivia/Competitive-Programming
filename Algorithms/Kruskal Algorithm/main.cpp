#include <iostream>
#include <vector>
#include <algorithm> // sort
#include <cstring> // Memset

using namespace std;

/*
    Font: Geeks for geeks

    What is Kruskal Algorithm:
    Kruskal's algorithm is a minimum spanning tree algorithm that takes a graph as input and finds the subset of the edges of that graph which
    form a tree that includes every vertex

    What is a spanning tree:
    Given a connected and undirected graph, a spanning tree of that graph is a subgraph that is a
    tree and connects all the vertices together. A single graph can have many different spanning trees.
    A minimum spanning tree (MST) or minimum weight spanning tree for a weighted, connected and undirected
    graph is a spanning tree with weight less than or equal to the weight of every other spanning tree.
    The weight of a spanning tree is the sum of weights given to each edge of the spanning tree.

    has the minimum sum of weights among all the trees that can be formed from the graph

    It is greedy algorithms which find the local optimum in the hopes of finding a global optimum.
    They are shortsighted in their approach in the sense that they take decisions on the basis of information at hand without worrying about the effect these decisions may have in the future. They are easy to invent, easy to implement and most of the time quite efficient. Many problems cannot be solved correctly by greedy approach. Greedy algorithms are used to solve optimization problems

    Greedy Algorithm works by making the decision that seems most promising at any moment; it never reconsiders this decision, whatever situation may arise later.

    *** ARVORE GERADORA MINIMA ***
*/

class Edge {
private:
    int v1, v2, weight;
public:
    Edge(int v1, int v2, int weight) : v1(v1), v2(v2), weight(weight) {}
    int getVertex1() {
        return this->v1;
    }

    int getVertex2() {
        return this->v2;
    }

    int getWeight() {
        return this->weight;
    }

    // Operator overloaded of "<", to sort according to the weight
    bool operator < (const Edge& ed2) const {
        return (weight < ed2.weight);
    }
};

class Graph {
private:
    int n_vertex; // Number of vertex
    vector<Edge>edges; // vector of edges
public:
    Graph(int n_vertex) : n_vertex(n_vertex) {}

    // Function to add edge
    void addEdge(int v1, int v2, int weight) {
        Edge edge(v1,v2,weight);
        edges.push_back(edge);
    }

    // Function to find (subset) of a element
    int find_unionFind(int subset[], int vertex) {
        if(subset[vertex] == -1)
            return vertex;
        else
            return find_unionFind(subset,subset[vertex]);
    }
    // function to join two subsets in one
    void join(int subset[], int vertex1, int vertex2) {
        vertex1 = find_unionFind(subset,vertex1);
        vertex2 = find_unionFind(subset,vertex2);
        subset[vertex1] = vertex2;
    }

    // kruskal function
    void kruskal() {
        vector<Edge>tree; // Will store all edges that is going to be part of the tree
        int size_edge = edges.size();


        // Sort edges according to weight
        sort(edges.begin(),edges.end());

        // Allocate memory to create n_vertex subsets
        int *subset = new int[this->n_vertex];
        memset(subset,-1,sizeof(int) * n_vertex);

        for(int i = 0; i < size_edge; i++) {
            int v1 = find_unionFind(subset,edges[i].getVertex1());
            int v2 = find_unionFind(subset,edges[i].getVertex2());

            if(v1 != v2) { // This edge belongs to the tree, there's no cycle
                tree.push_back(edges[i]); // insert in the vector
                join(subset, v1,v2); // Joining it.
            }
        }

        int size_tree = tree.size();

        // Show edges with its respective weights
        for(int i = 0; i < size_tree; i++) {
            cout << "( " << ((char)('A' + tree[i].getVertex1())) << " , " << ((char)('A' + tree[i].getVertex2())) << " ) = " << tree[i].getWeight() << endl;
        }
    }
};

int main()
{

    Graph g(4);


    g.addEdge(1, 2, 50);
	g.addEdge(3, 1, 75);
	g.addEdge(2, 3, 20);
	g.addEdge(4, 2, 10);
	g.addEdge(3, 4, 15);

    g.kruskal();


    return 0;
}
