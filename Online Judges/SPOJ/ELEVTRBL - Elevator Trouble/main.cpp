#include <iostream>
#include <vector>
#include <queue>

using namespace std;



int main()
{
    // F = n floors, S = start, g = goal, u = n floors up, d = n floors down
    int f, s, g, u, d, nstep = 0;
    cin >> f >> s >> g >> u >> d;
    vector<int>dist(f, -1);
    queue<pair<int,int> >q;
    --s, --g;
    q.push({s,0});

    while(!q.empty()) {
        pair<int,int>p = q.front();
        q.pop();
        if(dist[p.first] == -1) {
            dist[p.first] = p.second;
            if(p.first + u < f) {
                q.push({p.first + u, p.second + 1});
            }
            if(p.first - d >= 0) {
                q.push({p.first - d, p.second + 1});
            }
        }
    }

    if(dist[g] == -1)
        cout << "use the stairs\n";
    else
        cout << dist[g] << endl;
    return 0;
}
