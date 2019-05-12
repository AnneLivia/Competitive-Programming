#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct cs {
    int c, h, l;
};

bool compare(const cs& c1, const cs& c2) {
    return (c1.c < c2.c);
}

int main()
{

    int n;
    cin >> n;

    vector<cs>cc(n, {0,0,0});

    for (int i = 0; i < n; i++) {
        cin >> cc[i].c >> cc[i].h >> cc[i].l;
    }

    sort(cc.begin(), cc.end(), compare);

    bool can = true;
    for (int i = 0; i < n - 1; i++) {
        if(cc[i].c < cc[i + 1].c && cc[i].h >= cc[i + 1].h || cc[i].l >= cc[i + 1].l) {
            can = false;
            break;
        }
    }
    if(can)
        cout << "S\n";
    else
        cout << "N\n";

    return 0;
}
