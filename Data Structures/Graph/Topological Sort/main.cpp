#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;

/*
    Topological sorting for Directed Acyclic Graph (DAG) is a linear
    ordering of vertices such that for every directed edge uv, vertex
    u comes before v in the ordering. Topological Sorting for a graph
    is not possible if the graph is not a DAG.

    The first vertex in topological sorting is always a vertex
    with in-degree as 0 (a vertex with no incoming edges).
    A sink is a vertex that has out degree 0
    A source is a vertex that has in-degree 0;
*/

class Graph {
private:
    list<int> *adj;
    vector<int> indegree, outdegree; // Vectors to store number of in-degree and out-degree of each vertex
    int nVertex;
public:
    Graph(int v) : nVertex(v) {
        adj = new list<int>[this->nVertex];
        indegree.assign(this->nVertex, 0);
        outdegree.assign(this->nVertex, 0);
    }

    void createAnArc(int vertex1, int vertex2) {
        this->adj[vertex1].push_back(vertex2);
        this->indegree[vertex2]++;
        this->outdegree[vertex1]++;
    }
    /*
        For this DAG:
        [0] -> null (sink vertex)
        [1] -> null (sink vertex)
        [2] -> 3
        [3] -> 1
        [4] -> 0 -> 1 (source vertex)
        [5] -> 0 -> 2 (source vertex)

        A topological sorting can be: 5 4 2 3 1 0, and it also can be: 4 5 2 3 1 0

        Topological Sorting vs Depth First Traversal (DFS):

        In DFS, we print a vertex and then recursively call DFS for
        its adjacent vertices. In topological sorting, we need to
        print a vertex before its adjacent vertices. For example,
        in the given graph, the vertex ‘5’ should be printed before vertex ‘0’,
        but unlike DFS, the vertex ‘4’ should also be printed before vertex ‘0’.
        So Topological sorting is different from DFS. For example, a DFS of
        the shown graph could be “5 2 3 1 0 4”, but it is not a topological sorting
    */

    // Topological Sort in a DAG (Recursive)
    void topological_recursive(int& vertex, int visited[], stack<int>&s) {

        // Current node is visited
        visited[vertex] = 1;

        // Running all its adjacent nodes to push into the stack
        for(auto adjVertex : adj[vertex]) {
            if(!visited[adjVertex])
                topological_recursive(adjVertex, visited, s);
        }

        // Insert the sink vertex into the stack
        s.push(vertex);
    }

    void topological_sr() {
        int visited[this->nVertex];
        memset(visited, 0, sizeof(int) * this->nVertex);

        stack<int>s;
        list<int>::iterator it;
        for (int i = 0; i < this->nVertex; i++) {
            if(!visited[i])
                topological_recursive(i, visited, s);
        }

        // post[u] < post[v], nodes with the highest post come before
        while(!s.empty()) {
            cout << s.top() << endl;
            s.pop();
        }
    }

    /*
        The above algorithm is simply DFS with an extra stack.
        So time complexity is same as DFS which is O(V+E).

    */

    /* All topological Sort
       Information taken from (Geeks for geeks)
       In a Directed acyclic graph many a times we can have
       vertexes which are unrelated to each other because of
       which we can order them in many ways. These various
       topological sorting is important in many cases, for
       example if some relative weight is also available
       between the vertexes, which is to minimize then we
       need to take care of relative ordering as well as
       their relative weight, which creates the need of
       checking through all possible topological ordering.

       We can go through all possible ordering via backtracking , the algorithm step are as follows :
       1 - Initialize all vertexes as unvisited.
       2 - Now choose vertex which is unvisited and has zero in-degree and decrease in-degree
       of all those vertexes by 1 (corresponding to removing edges) now add this vertex
       to result and call the recursive function again and backtrack.
       After returning from function reset values of visited, result and in-degree for enumeration
       of other possibilities.
    */

    void alltopological() {
        bool visited[this->nVertex];
        memset(visited, false, sizeof(int) * this->nVertex);

        vector<int>result;
        all_topological_work(result, visited);
    }

    void all_topological_work(vector<int>& result, bool visited[]) {
        bool all_top = false; // to indicate if all topological sort were found or not

        // Run through all vertexes
        for (int i = 0; i < this->nVertex; i++) {
            // Choosing vertex that has in-degree 0 (source) and was not visited yet
            if(this->indegree[i] == 0 && !visited[i]) {
                for (auto it = this->adj[i].begin(); it != this->adj[i].end(); it++) {
                    // Decreasing all in-degree of adjacent vertexes of i
                    this->indegree[*it]--;
                }
                // After decreasing in-degree of its adjacent, include I in result vector
                result.push_back(i);
                visited[i] = true;
                // Call recursively the function again, searching for another 0 in-degree
                all_topological_work(result, visited);

                // resetting visited, result and in-degree for backtracking
                // resetting visited, res and indegree for
                // backtracking
                visited[i] = false;
                result.erase(result.end() - 1); // Erasing from stack the last one
                for (auto it = adj[i].begin(); it != adj[i].end(); it++)
                    indegree[*it]++; // increasing in-degree of all adjacent to one again

                all_top = true; // mark that all top were already visited and printed
            }
        }

        // When all vertex are visited, then it can be printed
        if (!all_top) {
            for (int i = 0; i < (int)result.size(); i++) {
                if(i != 0)
                    cout << " ";
                cout << result[i];
            }
            cout << endl;
        }
    }

    // Topological sort another algorithm removing sources
    void topSort() {
        queue<int>q;
        vector<int>v; v.assign(this->nVertex, 0);
        // Inserting all in-degree(source) vertex in the queue
        for (int i = 0; i < this->nVertex; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        int t = 0; // index used to insert element in v
        while(!q.empty()) {
            int w = q.front(); // First element
            v[t++] = w; // inserting (no in-degree) source vertex in the array
            for(auto it = adj[w].begin(); it != adj[w].end(); it++) {
                // Decreasing by one all adjacent of w
                indegree[*it]--;
                // In case there's another source vertex, insert it into the queue
                if(indegree[*it] == 0)
                    q.push(*it);
            }

            q.pop(); // Removing from queue
        }

        for (int i = 0; i < (int)v.size(); i++) {
            if(i != 0)
                cout << " ";
            cout << v[i];
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

    // Creating a DAG (directed acyclic graph)

    g.createAnArc(5,2);
    g.createAnArc(5,0);
    g.createAnArc(4,0);
    g.createAnArc(4,1);
    g.createAnArc(2,3);
    g.createAnArc(3,1);

    /*
        All topological sorts of the given graph are:
        4 5 0 2 3 1
        4 5 2 0 3 1
        4 5 2 3 0 1
        4 5 2 3 1 0
        5 2 3 4 0 1
        5 2 3 4 1 0
        5 2 4 0 3 1
        5 2 4 3 0 1
        5 2 4 3 1 0
        5 4 0 2 3 1
        5 4 2 0 3 1
        5 4 2 3 0 1
        5 4 2 3 1 0
    */

    cout << "Printing all topological sort: \n";
    g.topSort();

    return 0;
}
