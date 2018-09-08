#include <iostream>
#include <list>
#include <stack>
#include <cstring>
#include <cstdlib>

using namespace std;

/*
    Union-Find Algorithm or Disjoint set union can be used to check whether an undirected graph contains cycle or not
    Union and Find:
    Find -> searches for a subset of a element, it determines if two elements are in the same set
    Union -> merge two subset in a set.


*/

// Function that searches for a subset
int unionFind_find(int subset[], int v) {
    if(subset[v] == -1)
        return v;
    return unionFind_find(subset, subset[v]);
}

// Function to join two subsets in a unique set
void unionFind_union(int subset[], int v1, int v2) {
    int v1_set = unionFind_find(subset,v1);
    int v2_set = unionFind_find(subset,v2);

    subset[v1_set] = v2_set;
}

int has_cycle(int graph[3][3]) {
    int *subset = (int *)malloc(3 * sizeof(int));

    memset(subset, -1, sizeof(int) * 3);
    for(int i = 0; i < 3; i++) {
        for(int j = i; j < 3; j++) {
            if(graph[i][j] == 1) { // If there's edge
                int v1 = unionFind_find(subset,i);
                int v2 = unionFind_find(subset,j);
                if(v1 == v2)
                    return 1;
                else
                    unionFind_union(subset,v1,v2);
            }
        }
    }
    return 0;
}

int main()
{
    int graph[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}; // adjacency matrix

    /*
        1 - 2
         \ /
          3

        Graph with cycle, union find must return that it has cycle

        It has 2 functions, find and union:
        find is responsible for find its parent index
        union is responsible to merge it.

        vet[3] = {-1, -1, -1}

        v(1,2)

        v1 = 1, v2 = 2;

        v1 = find(vet,v1);
        v2 = find(vet,v2);

        find(vet, vertex):
            if(vet[vertex] == -1)
                return vertex;
            return find(vet,vet[vertex]);
        after done that, calls function union

        union(vet,v1, v2):
            v1 = find(vet,v1);
            v2 = find(vet,v2);
            if(v1 == v2):
                it has cycle
            else
                vet[v1] = v2;
    */

    // Undirected graph
    graph[0][1] = 1;
    graph[1][0] = 1;
    graph[1][2] = 1;
    graph[2][1] = 1;
    graph[0][2] = 1;
    graph[2][0] = 1;

    if(has_cycle(graph))
        cout << "The graph has cycle\n";
    else
        cout << "Graph has no cycle\n";

    return 0;
}
