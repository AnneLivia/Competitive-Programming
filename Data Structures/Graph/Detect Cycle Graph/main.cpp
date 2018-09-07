#include <iostream>
#include <list>
#include <stack>

using namespace std;

class Graph {
private:
    int v_amount;
    list<int> *graph;

public:
    Graph(int v_amount) {
        this->v_amount = v_amount;
        this->graph = new list<int>[this->v_amount];
    }

    void insert_edge(int vertex1, int vertex2) {
        this->graph[vertex1].push_back(vertex2);
    }

    /*
            0 - 1
           / \ /
         2    3
    */

    // Algorithm must be done with each vertex

    // Do a DFS start from a vertex, return if it has found a cycle or not
    bool dfs(int vertex) {
        int visited_vertex[this->v_amount];
        int rec_stack[this->v_amount]; // Check it a specific element is at the stack

        for(int i = 0; i < this->v_amount; i++) {
            visited_vertex[i] = 0;
            rec_stack[i] = 0;
        }

        stack<int>p;

        while(true) {

            bool found_neighbor = false;

            if(!visited_vertex[vertex]) {
                visited_vertex[vertex] = 1; // vertex was visited
                rec_stack[vertex] = 1; // vertex is at the stack
                p.push(vertex); // Add it at the stack
            }

            int aux_vertex;

            for(auto it = graph[vertex].begin(); it != graph[vertex].end(); it++) {
                if(rec_stack[*it]) {
                    // if this neighbor is at the rec_stack, it means that the vertex was already visited
                    return true;
                } else if (!visited_vertex[*it]) {
                    // If it was not visited yet
                    aux_vertex = *it;
                    found_neighbor = true;
                    break;
                }
            }

            if(found_neighbor) {
                vertex = aux_vertex;
            } else {
                rec_stack[p.top()] = false; // Get it off the stack
                p.pop();
                if(!p.empty()) {
                    vertex = p.top();
                } else {
                    break;
                }
            }
        }
        return false;
    }

    // Verify if this has a circle
    bool hasCycle() {
        for(int i = 0; i < this->v_amount; i++) {
            if(dfs(i)) {
                return true;
            }
        }

        return false;
    }
};
int main()
{
    Graph g(4);
    g.insert_edge(0,1);
    g.insert_edge(0,2);
    g.insert_edge(1,3);
    g.insert_edge(3,0);

    cout << "Vertex 0 has circle ?\n";
    if(g.dfs(2)) {
        cout << "yes...\n\n";
    } else {
        cout << "no...\n\n";
    }

    cout << "Detecting if a graph has cycle, checking from any vertex\n";
    if(g.hasCycle()) {
        cout << "Graph has cycle\n";
    } else {
        cout << "Graph has not any cycle\n";
    }
    return 0;
}
