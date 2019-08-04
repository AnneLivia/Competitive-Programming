#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Airport {
    int id, total;
    /*
    bool operator < (const Airport& ai) {
        return this->total < ai.total;
    }
    */
};

vector<vector<int > > flights;
vector<Airport>cont;
vector<bool>vi;

void bfs_aux(int v) {
    queue<int>q;
    q.push(v);

    while(!q.empty()) {

        int u = q.front();
        q.pop();

        if(!vi[u]) {
            cont[u].total += (int)flights[u].size();
            vi[u] = true;
           // cout << "Checking " << u + 1 << " flight: " << cont[u].total << endl;
            for (int i = 0; i < (int)flights[u].size(); i++) {
                //cout << " ->> " << flights[u][i] + 1 << endl;
                cont[flights[u][i]].total++;
                if(!vi[flights[u][i]]) {
                    q.push(flights[u][i]);
                }
            }
        }
    }
}

void bfs() {
    for (int i = 0; i < (int)flights.size(); i++) {
        if(!vi[i]) {
            bfs_aux(i);
        }
    }
}

int main()
{
    int na, nf, x, y, t = 1;


    while(cin >> na >> nf && na && nf) {
        flights.assign(na, vector<int>());
        vi.assign(na, false);

        cont.assign(na, {0,0});

        for (int i = 0; i < na; i++) {
            cont[i].id = i;
        }

        while(nf--) {
            cin >> x >> y;
            --x;
            --y;
            flights[x].push_back(y);
        }

        bfs();

        sort(cont.begin(), cont.end(), [](const Airport& a1, const Airport& a2) -> bool {
            if(a1.total > a2.total)
                return true;
            else if (a1.total == a2.total) {
                if(a1.id < a2.id)
                    return true;
            }
            return false;
        });

        cout << "Teste " << t++ << endl;
        int space = 0, i = 0;
        for (i = 0; i < na - 1; i++) {
            if(cont[i].total == cont[i + 1].total) {
                if(space)
                    cout << " ";
                cout << cont[i].id + 1;
                space = 1;
            } else {
                if(space)
                    cout << " ";
                cout << cont[i].id + 1;
                break;
            }
        }

        if(i == na - 1 && cont[i].total == cont[i - 1].total) {
            cout << " " << cont[i].id + 1;
       }

        cout << "\n\n";
    }


    return 0;
}
