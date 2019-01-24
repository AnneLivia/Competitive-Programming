#include <iostream>
#include <list>
#include <vector>
#include <array>
#include <stack>

using namespace std;

/*
    Strong connectivity applies only to directed graphs. A directed graph is strongly
    connected if there is a directed path from any vertex to every other vertex. This is
    same as connectivity in an undirected graph, the only difference being strong connectivity
    applies to directed graphs and there should be directed paths instead of just paths.
    Similar to connected components, a directed graph can be broken down into Strongly Connected
    Components. If a directed graph has only one component, then this graph is strongly connected.
    when we have strongly connected components, those components can be represented as Meta graphs,
    that are connected with edges that make them a DAG (directed acyclic graph).
    A simple way to verify if a graph is strongly connected or not, or even find its strongly connected
    components, is basically verify if each one of its vertexes is within reach of each other. but this algorithm is
    too slow, in the worst case its complexity is V^2(V+A), the algorithm is inefficient because it redo many calculus,
    that it is not necessary, the calculus relativity to a pair o vertex, repeats in many of the calculus relativity to other
    pair of vertex.
    ->>> There can be many SCCs in a graph. But no two SCCs can have a common node. Because if such a node exist,
    ->>> then they can be merged into a single SCC.

    -> Some Applications:
        - SCC algorithms can be used as a first step for many graphs algorithms that work on strongly connected components
        - In social networks, a group of people are generally strongly connected (For example, students of a class or any
        other common place). Many people in these groups generally like some common pages or play common games.
        The SCC algorithms can be used to find such groups and suggest the commonly liked pages or games to the people
        in the group who have not yet liked commonly liked a page or played a game.

    Kosaraju's Algorithm is one way to find strongly connected components of a graph in O(V + E),
    This algorithms makes use of the fact that the transpose graph (the same graph with the,
    direction of every edge reversed) has exactly the same strongly connected components as the original
    graph. The steps of the algorithm are:
    1 - create an empty stack and do a DFS transversal, and push vertexes into the stack.
    2 - reverse directions of all arcs to obtain transpose graph
    3 - one by one pop a vertex from the stack created, and while the stack is not empty,
    take the vertex popped and do a DFS. all the vertexes that belongs to the vertex popped
    are of the same strongly connected components.

    The kosaraju-Sharir's algorithm is DFS based. It does DFS two times.
    - First one to number the vertices according to their finish time
    - second one to get the actual SCCs.

    Let's say that we have this graph:
    0 -> 3 -> 2
    1 -> 0
    2 -> 1
    3 -> 4
    4 -> null
    - Example, after calling the DFS starting from 0, we are going to get a stack as:
    top -> 0, 3, 4, 2, 1.
    - Now, we reverse directions of all arcs to obtain the transpose graph, this can simply be done
    by creating a new graph and for each adjacent vertex of V, insert the V in its adjacent.
    It could looks like this:
    0 -> 1
    1 -> 2
    2 -> 0
    3 -> 0
    4 -> 3
    One by one pop a vertex from S while S is not empty.
    - Let the popped vertex be "V". Take V as source and do DFS.
    The DFS starting from v prints strongly connected component of v.
    In the above example, we process vertexes in order 0, 3, 4, 2, 1 (One by one popped from stack).
    starting from 0:
        alreadyVisited[] = {0}, pop 0 from stack, now stack is: 3, 4, 2, 1
        DFS(0) in the reversed graph -> 1
        alreadyVisited[] = {0, 1}
        DFS(1) in the reversed graph -> 2
        alreadyVisited[] = {0, 1, 2}
        DFS(2) in the reversed graph -> 0, but 0 was already visited, then backtrack
        DFS(1) no other adjacent
        DFS(0) no other adjacent
        First strongly connected component is (0,1,2).
        pop top which is 3 from stack, now stack is: 4, 2, 1 and check if it has been visited,
        since it was not, alreadyVisited[] = {0, 1, 2, 3}
        DFS(3) in the reversed graph -> 0, but 0 was already visited, then backtrack
        DFS(3) no other adjacent, then: second strongly connected component is (3).
        pop top which is 4 from stack and check if it has been visited, since it was not,
        alreadyVisited[] = {0, 1, 2, 3}, 4.
        DFS(4) in the reversed graph -> 3, but 3 was already visited, then backtrack
        DFS(4) no other adjacent, then: third strongly connected component is (4).
        the strongly connected components of the example graph are: (0,1,2,3), (3) and (4). Three connected components

    Why get the transposed of a graph in this algorithm ?
    This is based upon this: if vertex v can reach u, the if I reverse u, for sure I can reach v,
    but otherwise, if v cannot reach u, then u cannot reach v.
*/

class Graph {
private:
    list<int> *adj;
    int n_vertex;
public:
    Graph(int n_vertex) : n_vertex(n_vertex) {
        this->adj = new list<int>[this->n_vertex];
    }

    void createEdge(int u, int v) {
        this->adj[u].push_back(v);
    }

    void showEdges() {
        for (int u = 0; u < n_vertex; u++) {
            cout << u << " -> ";
            if(this->adj[u].size() == 0)
                cout << " null";
            int first = 0;
            for (auto v : this->adj[u]) {
                if(first) {
                    cout << ", ";
                }
                cout << v;
                first = 1;
            }
            cout << endl;
        }
    }

    // Transpose or reversed or converse of a graph is done by inverting
    // the edge, that is, if G that contains an edge (v,u), then the reversed
    // is (u,v) and vice versa.

    Graph transposeG() {
        Graph g(this->n_vertex); // Create a new vertex that is going to receive the transpose graph
        // For all vertexes
        for (int i = 0; i < n_vertex; i++) {
            // run though all adjacent of I vertex.
            for (auto it = adj[i].begin(); it != adj[i].end(); it++) {
                // for each (i,v) create in the new graph (transpose) an edge (v,i)
                g.createEdge(*it, i); // In each adjacent of i, its adjacent now is going to point to i
            }
        }

        return g; // return transpose, reversed or converse of G graph
    }

    // DFS algorithm to perform the first step and third step of Kosaraju's algorihm
    void dfs(vector<int>& vi, int v) {
        cout << v << " -> ";
        vi[v] = 1;
        for (auto it = this->adj[v].begin(); it != this->adj[v].end(); it++) {
            if(!vi[*it]) {
                dfs(vi, *it);
            }
        }
    }

    // Method to do a DFS and push vertexes into a stack
    void completeDFS(vector<int>& vi, stack<int>& s, int v) {
        vi[v] = true;
        for (auto it = adj[v].begin(); it != adj[v].end(); it++) {
            if(!vi[*it])
                completeDFS(vi, s, *it);
        }
        s.push(v);
    }

    // Method to perform kosaraju algorithm to find SCC of a graph and count how many SCC of a graph there are.
    void kosarajuAlgorithm() {
        int numberOfSCC = 0;

        // creating a vector that check if a vertex was already visited or not
        vector<int>vi(this->n_vertex, 0);

        // Creating empty stack to find an ordering of the graph vertexes that serves the execution
        // of the DFS algorithm on the reversed graph
        stack<int>s;

        // DFS in the graph to store the reverse order in the stack
        for (int i = 0; i < this->n_vertex; i++) {
            if(!vi[i])
                completeDFS(vi, s, i);
        }

        // get the transpose of the graph to perform reverse DFS, "from back to front"
        Graph transpose = transposeG();

        // Clear visited vector, to do DFS again, but now with the transpose Graph
        vi.assign(this->n_vertex, 0);

        // Run DFS in the Transpose Graph ("from the back")
        while(!s.empty()) {
            int v = s.top();
            s.pop();
            if(!vi[v]) {
                transpose.dfs(vi, v); // doing DFS in the transpose graph
                cout << "null\n";
                numberOfSCC++;
            }
        }

        cout << "There are " << numberOfSCC << " SCCs\n";
    }

    ~Graph() {
        delete[] adj;
    }
};

int main()
{
    Graph g(3);
    g.createEdge(0, 1);
    g.createEdge(1, 0);
    g.createEdge(0, 2);

    cout << "Original graph: \n";
    g.showEdges();
    cout << "Transpose Graph: \n";
    g.transposeG().showEdges();
    cout << "Strongly Connected Components: \n";
    g.kosarajuAlgorithm();
    return 0;
}
