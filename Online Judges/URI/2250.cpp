#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Player {
    int points;
    string name;

    bool operator < (const Player& pp) {
        if (this->points > pp.points) {
            return true;
        } else if (pp.points == this->points) {
            if (this->name < pp.name)
                return true;
        }
        return false;
    }
};

int main() {
    int n, x, mi, ma,t = 1;
    vector<Player>v;
    while(cin >> n && n) {
        v.assign(n, {0, ""});
        for (int i = 0; i < n; i++)
        {
            cin >> v[i].name;
            mi = 100000, ma = -1;
            for (int j = 0; j < 12; j++)
            {
                cin >> x;
                if (x < mi) mi = x;
                if (x > ma) ma = x;

                v[i].points+=x;
            }
            v[i].points-=(mi+ma);
        }

        sort(v.begin(), v.end());
        int rank = 1, pos = 1;
        cout << "Teste " << t++ << endl;
        for (int i = 0; i < n; i++)
        {
            if (i != 0) {
                rank++;
                if (v[i].points != v[i - 1].points) {
                    pos = rank;
                }
            } 

            cout << pos << " " << v[i].points << " " << v[i].name << endl; 
        }
        cout << endl;
    }
    return 0;  
}
