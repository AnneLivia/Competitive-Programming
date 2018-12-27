#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;
vii v;

bool dfs(int vertex) {
    vi visited((int)v.size(), 0);
    vi jaEsta((int)v.size(), 0);

    stack<int>p;

    while(true) {
        if(!visited[vertex]) {
            p.push(vertex);
            visited[vertex] = 1;
            jaEsta[vertex] = 1;
        }

        int auxVertex = vertex, found_neighbour = false;
        for (int i = 0; i < (int)v[vertex].size(); i++) {
            if(jaEsta[v[vertex][i]]) {
                return true; // loop
            }

            if(!visited[v[vertex][i]]) {
                auxVertex = v[vertex][i];
                found_neighbour = true;
                break;
            }
        }

        if(found_neighbour) {
            vertex = auxVertex;
        } else {
            jaEsta[p.top()] = false;
            p.pop();
            if(!p.empty())
                vertex = p.top();
            else
                break;
        }
    }

    return false;
}

bool hasCicle() {
    for (int i = 1; i < (int)v.size(); i++) {
        if(dfs(i))
            return true;
    }
    return false;
}

int main()
{
    int t, x, y, d;
    cin >> t;
    while(t--) {
        cin >> x >> d;
        v.assign(x + 1, vi());
        while(d--) {
            cin >> x >> y;
            v[x].push_back(y);
        }

        if(hasCicle())
            cout << "SIM" << endl;
        else
            cout << "NAO" << endl;
    }
    return 0;
}
