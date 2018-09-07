#include <iostream>
#include <list>
#include <queue>
#include <stack>

using namespace std;

class Graph {
private:
    int v_amount;
    list<int> *graph;
    // It's going to be privet, so that only the class can use
    void dfs_aux(int vertex, int visited[]) {
        if(!visited[vertex]) {
            visited[vertex] = 1;
        }

        cout << "Vertex: " << vertex << " ..." << endl;
        for(auto it = graph[vertex].begin(); it != graph[vertex].end(); it++) {
            if(!visited[*it]) {
                dfs_aux(*it,visited);
            }
        }
    }
public:
    Graph(int v_amount) {
        this->v_amount = v_amount;
        this->graph = new list<int>[this->v_amount];
    }

    void create_edge(int vertex1, int vertex2) {
        if(vertex1 >= 0 && vertex1 <= this->v_amount &&
           vertex2 >= 0 && vertex2 <= this->v_amount) {
            this->graph[vertex1].push_back(vertex2);
        }
    }



    void dfs_with_recursion(int vertex) {
        int visited_vertices[this->v_amount];
        for(int i = 0; i < this->v_amount; i++) {
            visited_vertices[i] = 0;
        }

        dfs_aux(vertex, visited_vertices); // Starting with the first node
    }

    void dfs_with_stack(int v) {
        int visited_vertices[this->v_amount];
        for(int i = 0; i < this->v_amount; i++) {
            visited_vertices[i] = 0; // None was visited yet
        }

        stack<int>p;

        while(true) {

            if(!visited_vertices[v]) {
                cout << "Vertex: " << v << " ..." << endl;
                p.push(v);
                visited_vertices[v] = 1; // True;
            }

            bool found_n_visited = false;

            int aux_v = v;
            for(auto it = graph[v].begin(); it != graph[v].end(); it++) {
                // If vertex in graph (v) was not visited yet
                if(!visited_vertices[*it]) {
                    found_n_visited = true; // Found
                    aux_v = *it;
                    break;
                }
            }
            // If it has found
            if(found_n_visited) {
                v = aux_v; // Now v is found vertex
            } else {
                // v vertex hasn't any child
                p.pop(); // Remove this v child now

                // If after pop the stack is empty, then the loop must stop, all vertex or nodes were visited
                if(p.empty()) {
                    break;
                }

                // otherwise, update v, with the vertex at the top
                v = p.top();
            }
        }
    }

    /*
            0
         /    \
        1      3
       / \
      5   6

      In BFS will be printed:
      0
      1
      3
      5
      6

      -> For another example:

            0
         /    \
        1      2
       / \    / \
      3   4  5   6
                  \
                   7

      Start at the root and run through all the neighbors

      First: root 0
      add at the queue: 1 and 2
      then take 1, and add its child, 3 and 4:
      then take 2, and add its child, 5 and 6:
      then take 3, and add its child, it doesn't have any.
      then take 4, and add its child, it doesn't have any.
      then take 5, and add its child, it doesn't have any.
      then take 6, and add its child, 7.
      then take 7, and add its child, it doesn't have any.

      pop all.

      Algorithm:
      run through all neighbors
       if neighbor hasn't been visited
        mark it as visited
        push the neighbor at the queue

      if the queue is not empty
        vertex = queue.front();
        queue.remove_front();
      else
        exit
    */
    void bfs_with_queue(int vertex) {
        int visited_vertex[this->v_amount];
        for(int i = 0; i < this->v_amount; i++) {
            visited_vertex[i] = 0; // none was visited yet
        }

        queue<int>q; // Will control the breadth first search - BFS

        visited_vertex[vertex] = 1; // Mark the first one as visited

        cout << "Vertex " << vertex << " ...\n";

        while(true) {

            for(auto it = graph[vertex].begin(); it != graph[vertex].end(); it++) {
                if(!visited_vertex[*it]) {
                    cout << "Vertex " << *it << " ...\n";
                    visited_vertex[*it] = 1; // Mark as visited
                    q.push(*it); // Add it to the queue
                }
            }

            if(!q.empty()) {
                vertex = q.front(); // Update value
                q.pop(); // Remove it from the queue
            } else {
                break; // All elements were visited
            }
        }
    }
};

int main()
{
    Graph g(8);
    g.create_edge(0,1);
    g.create_edge(0,2);
    g.create_edge(1,3);
    g.create_edge(1,4);
    g.create_edge(2,5);
    g.create_edge(2,6);
    g.create_edge(6,7);

    cout << "DFS -> recursion\n\n";
    g.dfs_with_recursion(0);
    cout << "\n\nDFS -> stack\n\n";
    g.dfs_with_stack(0);
    cout << "\n\nBFS -> queue\n\n";
    g.bfs_with_queue(0);
    return 0;
}
