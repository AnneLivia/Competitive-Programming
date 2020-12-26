#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Rank {
    int level, xp, last_min_msg, cont_xp_level;
};

int main() {
    map<string, Rank> users;
    int n, m, k;
    string name;
    Rank aux;

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> m;   
        if (users.find(name) != users.end()) {
            if ((m - users.at(name).last_min_msg) >= k) {
                users.at(name).xp+=25;
                users.at(name).cont_xp_level+=25;
                if (users.at(name).cont_xp_level >= 100) {
                    users.at(name).level++;  
                    users.at(name).cont_xp_level = 0;  
                }
                users.at(name).last_min_msg = m;
            }
        } else {
            int mm = m;
            if (m < k)
                mm = 0;
            users.insert({name, {1, 25, mm, 25}});
        }
    }

    vector<pair<string, Rank> > cop;
    
    cout << "--Rank do Nepscord--\n";
    for (auto i : users) {
        cop.push_back({i.first, i.second});
    }

    sort(cop.begin(), cop.end(), [](const pair<string, Rank>& p1, 
                                    const pair<string, Rank>& p2) -> bool {
        if (p1.second.xp > p2.second.xp)
            return true;
        else if (p1.second.xp == p2.second.xp) {
            if (p1.first < p2.first) {
                return true;
            }
        }
        return false;
    });

    int ss = 3;
    if ((int)cop.size() < 3)
        ss = (int)cop.size();
    for (int i = 0; i < ss; i++) {
        cout << "#" << i+1 << ". " << cop[i].first << " - Nivel " << cop[i].second.level << endl;
    }

    if (ss == 2) {
        cout << "#3.\n"; 
    } else if (ss == 1) {
        cout << "#2.\n#3.\n"; 
    } else if (ss == 0) {
        cout << "#1.\n#2.\n#3.\n"; 
    }

    return 0;  
}
