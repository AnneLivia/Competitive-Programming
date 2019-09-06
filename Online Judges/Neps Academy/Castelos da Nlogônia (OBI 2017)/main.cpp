#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<vector<int> > v;
vector<int>color;

void bfs(int x, int y, int c) {

    vector<int>path((int)color.size(), -1), vi((int)color.size(), 0);
    queue<int>q;
    q.push(x);

    while(!q.empty()) {
        int z = q.front();
        q.pop();
        if(!vi[z]) {
            vi[z] = 1;
            if(z == y)
                break;
            for (int i = 0; i < (int)v[z].size(); i++) {
                if (!vi[v[z][i]]) {
                    path[v[z][i]] = z;
                    q.push(v[z][i]);
                }
            }
        }
    }

    color[y] = c;

    while(path[y] != -1) {
        color[path[y]] = c;
        y = path[y];
    }

}

int main()
{
    int n, m, x, y, c;

    cin >> n >> m;

    v.assign(n, vector<int>());
    color.assign(n, 0);
    n--;
    while(n--) {
        cin >> x >> y;
        v[x - 1].push_back(y - 1);
        v[y - 1].push_back(x - 1);
    }

    while(m--) {
        cin >> x >> y >> c;
        bfs(x - 1, y - 1, c);
    }

    for (int i = 0; i < (int)color.size(); i++) {
        if(i != 0)
            cout << " ";
        cout << color[i];
    }
    cout << endl;
    return 0;
}
