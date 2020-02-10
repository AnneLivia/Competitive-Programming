#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstdlib>

using namespace std;

vector<vector<int> > g;
vector<vector<int> > inv;
vector<int>age;

void change(int a, int b) {
    vector<int> auxa, auxb;
    for (int i = 0; i < (int)inv[a].size(); i++) {
        if(inv[a][i] != b) {
            auxa.push_back(inv[a][i]);
        } else {
            // in this way, b is going to point to a
            // when assign back
            auxa.push_back(a);
        }
    }

    for (int i = 0; i < (int)inv[b].size(); i++) {
        if (inv[b][i] != a) {
            auxb.push_back(inv[b][i]);
        } else {
            auxb.push_back(b);
        }
    }

    /*
    cout << "BEFORE\n";
    for (int i = 1; i < (int)inv.size(); i++) {
        cout << "Node " << i <<  " >> ";
        for (int j = 0; j < (int)inv[i].size(); j++) {
            cout << inv[i][j] << ", ";
        }
        cout << endl;
    }*/

    int changed;
    // next step is to make nodes that points to a
    // and b starts pointing to the other one
    for (int i = 1; i < (int)inv.size(); i++) {
        for (int j = 0; j < (int)inv[i].size(); j++) {
            if (inv[i][j] == a) {
                inv[i][j] = b; // starts pointing to b
                changed = 1;
            }
            // if change is true, then current position "J" contains
            // b value, but this is not to be changed.
            if(!changed && inv[i][j] == b) {
                inv[i][j] = a;
            }

            changed = 0;
        }
    }

    // a is receiving whichever b points to and vice versa
    inv[a] = auxb;
    inv[b] = auxa;
    /*
    cout << "\n\nAFTEr\n";
    for (int i = 1; i < (int)inv.size(); i++) {
        cout << "Node " << i <<  " >> ";
        for (int j = 0; j < (int)inv[i].size(); j++) {
            cout << inv[i][j] << ", ";
        }
        cout << endl;
    }*/
}

void getInv() {
    for (int i = 1; i < (int)g.size(); i++) {
        for (int j = 0; j < (int)g[i].size(); j++) {
            inv[g[i][j]].push_back(i);
        }
    }
}

int question(int a) {
    stack<int>s;
    vector<int>vi((int)inv.size(), 0);
    s.push(a);
    int mm = 0x3f3f3f3f;
    while(!s.empty()) {
        int v = s.top(), found = 0;
        if(!vi[v]) {
            // cout << "Visiting " << v << " age: " << age[v] << endl;
            // getting minimum age
            if (v != a && age[v] < mm) {
                mm = age[v];
            }
            vi[v] = 1;
        }

        for (int i = 0; i < (int)inv[v].size(); i++) {
            if(!vi[inv[v][i]]) {
                found = 1;
                s.push(inv[v][i]);
                break;
            }
        }

        if(!found) {
            // there's no more nodes, remove it from stack
            s.pop();
        }
    }

    return mm;
}

int main()
{
    int n, m, e, a, b;
    char t;

    cin >> n >> m >> e;

    g.assign(n+1, vector<int>());
    age.assign(n+1,0);

    for (int i = 1; i <= n; i++) {
        cin >> age[i];
    }

    while(m--) {
        cin >> a >> b;
        g[a].push_back(b);
    }

    // there's no need to create an inverse of the graph,
    // this could be done above, make g[b].push_back(a),
    // but just for practice it was done in this way

    inv.assign(n+1, vector<int>());
    getInv();

    int x = 1;
    while(e--) {
        cin >> t;
        if (t == 'P') {
            cin >> a;
            int resp = question(a);
            if(resp == 0x3f3f3f3f)
                cout << "*\n";
            else
                cout << resp << endl;
        } else {
            cin >> a >> b;
            change(a, b);
        }
    }
    return 0;
}
