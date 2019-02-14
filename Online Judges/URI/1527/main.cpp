#include <iostream>
#include <vector>

using namespace std;

// Guilds 1527 URI and CODECAD

vector<int>points, id, sz;

int detect(int r) {
    if(r == id[r])
        return r;

    points[r] = points[id[r]];
    id[r] = detect(id[r]);
    return id[r];
}

void unify(int p, int q) {
    p = detect(p);
    q = detect(q);

    if(sz[p] > sz[q])
        swap(p,q);
    id[p] = id[q];
    points[q]+=points[p];
    sz[q]+=sz[p];
}

bool battle_winner(int g1, int g2) {
    g1 = detect(g1);
    g2 = detect(g2);

    int id1 = detect(0);

    if((points[g1] > points[g2] && id1 == g1) || (points[g2] > points[g1] && id1 == g2))
        return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int nplayer, nactions, op, g1, g2, wins;

    while(cin >> nplayer >> nactions && nplayer && nactions) {
        points.assign(nplayer, 0);
        id.assign(nplayer, 0);
        sz.assign(nplayer, 1);
        wins = 0;
        for (int i = 0; i < nplayer; i++) {
            cin >> points[i];
            id[i] = i;
        }

        while(nactions--) {
            cin >> op >> g1 >> g2;
            --g1; --g2;
            if(op == 1) { // Union
                if(detect(g1) != detect(g2))
                    unify(g1,g2);
            } else { // Battle
                if(battle_winner(g1, g2)) {
                    wins++;
                }
            }
        }
        cout << wins << endl;
    }
    return 0;
}
