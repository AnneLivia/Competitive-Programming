#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

struct car {
    int id, pont;
    vector<int>pos;
};

int main() {
    int g, p, s, k;
    vector<car>v, cop;
    vector<int>aa;

    while(cin >> g >> p && g && p) {
        v.assign(p, {0, 0, vector<int>(g, 0)});
        for (int i = 0; i < p; i++) {
            v[i].id = i + 1;
        }
        for(int i = 0; i < g; i++) {
            for (int j = 0; j < p; j++) {
                cin >> v[j].pos[i];
            }
        }

        cin >> s;
        while(s--) {
            // way of copy values to another vector
            cop.assign(v.begin(), v.end());
            int pp;
            cin >> k;
            for (int i = 0; i < k && i < p; i++) {
                cin >> pp;
                for(int t = 0; t < g; t++) {
                    sort(cop.begin(), cop.end(), [&t](const car& a1, const car& a2) {
                        return a1.pos[t] < a2.pos[t];
                    });
                    cop[i].pont+=pp;
                }
            }

            sort(cop.begin(), cop.end(), [](const car& a1, const car& a2) -> bool {
                return a1.pont > a2.pont;
            });

            aa.clear();

            aa.push_back(cop[0].id);

            for (int i = 1; i < p; i++) {
                 if(cop[i].pont == cop[i - 1].pont) {
                    aa.push_back(cop[i].id);
                } else
                    break;
            }

            sort(aa.begin(), aa.end());

            for (int i = 0; i < (int)aa.size(); i++) {
                if(i != 0)
                    cout << " ";
                cout << aa[i];
            }
            cout << endl;
        }
    }

    return 0;
}

