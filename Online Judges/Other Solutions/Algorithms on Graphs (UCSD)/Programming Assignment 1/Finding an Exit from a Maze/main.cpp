#include <iostream>
#include <vector>

using namespace std;

/*
    Problem Introduction A maze is a rectangular grid of cells with
    walls between some of adjacent cells. You would like to check
    whether there is a path from a given cell to a given exit from
    a maze where an exit is also a cell that lies on the border of
    the maze (in the example shown to the right there are two exits:
    one on the left border and one on the right border).
    For this, you represent the maze as an undirected graph:
    vertices of the graph are cells of the maze, two vertices
    are connected by an undirected edge if they are adjacent
    and there is no wall between them. Then, to check whether
    there is a path between two given cells in the maze,
    it suffices to check that there is a path between the
    corresponding two vertices in the graph.

    If there's path between u and v, answer 1, 0 otherwise.
*/

vector<vector<int>>g;
vector<int>vi, id;
bool found = 0;

// Using DFS
void dfs(int u, int v) {
    // Is there path between u and v?
    if(!vi[u]) {
        vi[u] = 1;
        for(int i = 0; i < (int)g[u].size(); i++) {
            if(g[u][i] == v)
                found = 1;
            if(!vi[g[u][i]])
                dfs(g[u][i], v);
        }
    }
}

// Using union find
int detect(int p) {
    if(p == id[p])
        return p;
    return detect(id[p]);
}

void unify(int p, int q) {
    id[detect(p)] = detect(q);
}

int main()
{
    int n, m, u, v;
    cin >> n >> m;

    g.assign(n, vector<int>());
    vi.assign(n, 0);

    while(m--) {
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }

    cin >> u >> v;
    dfs(u - 1, v - 1);
    cout << found << endl;
    return 0;
}
