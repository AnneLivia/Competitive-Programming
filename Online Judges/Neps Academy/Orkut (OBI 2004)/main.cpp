#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
vector<int>id, sz;

int findd(int p) {
    if (p == id[p])
        return p;
    sz[p] = sz[id[p]]; // all of them has the same sizes
    return id[p] = findd(id[p]);
}

void unionn(int p, int q) {
    int idp = findd(p);
    int idq = findd(q);

    if (sz[idp] > sz[idq])
        swap(idp, idq);

    id[idp] = idq;
    sz[idq]+=sz[idp];
}

int main()
{
    int n, ind, t = 1;
    string name;
    map<string,int> m;
    vector<string>aux;
    vector<pair<string, vector<string> > > network;
    while(cin >> n && n != 0) {
        m.clear();
        ind = 1;
        id.assign(n+1, 0);
        sz.assign(n+1, 1);
        network.clear();
        for (int i = 1; i <= n; i++) {
            cin >> name;
            m.insert({name, ind++});
            id[i] = i;
        }
        // 0 is the one
        int num;
        string nn;
        for (int i = 0; i < n; i++) {
            cin >> name >> num;
            aux.clear();
            while(num--) {
                cin >> nn;
                aux.push_back(nn);
            }

            network.push_back({name, aux});
        }

        sort(network.begin(), network.end(), [](const pair<string, vector<string> > a1
                                                , const pair<string, vector<string> > a2) -> bool {
                if (a1.second.size() < a2.second.size())
                    return true;
                else if (a1.first < a2.first)
                    return true;
                return false;
        });

        if (t != 1)
            cout << "\n";
        aux.clear();
        for(auto i : network) {
            if(i.second.size() == 0) {
                if (findd(m[i.first]) != findd(0)) {

                    unionn(m[i.first], 0);
                    aux.push_back(i.first);
                }
            } else {
                // if already has members, then keep going, otherwise, impossible made friends
                if ((int)aux.size() > 0) {
                    // stores if she is friend of everyone in the list
                    int pp = 1;
                    for (int ii = 0; ii < (int)i.second.size(); ii++) {
                        if (findd(m[i.second[ii]]) != findd(m[i.second[ii]])) {
                            pp = 0;
                            break;
                        }
                    }
                    // if it's true, she is friend of everyone in this list, the i.first can be her friend
                    if (pp) {
                        if (findd(m[i.first]) != findd(0))
                            unionn(m[i.first], 0);
                            aux.push_back(i.first);
                    }
                } else {
                    break;
                }
            }
        }
        cout << "Teste " << t++ << endl;
        // if has no friend, that is aux.size is zero, then
        if(aux.empty()) {
            cout << "impossivel\n";
        } else {
            for (int i = 0; i < (int)aux.size(); i++) {
                if (i != 0)
                    cout << " ";
                cout << aux[i];
            }
        }
        cout << "\n";
    }
    return 0;
}
