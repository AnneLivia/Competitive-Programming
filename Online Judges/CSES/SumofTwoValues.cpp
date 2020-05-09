#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Data {
    int id, value, enter;
};

int main() {
    int n, p;
    cin >> n >> p;
    vector<Data>v(n, {0,0});

    for (int i = 0; i < n; i++) {
        cin >> v[i].value;
        v[i].id = i+1;
    }

    sort(v.begin(), v.end(), [](const Data& a1, const Data& a2) -> bool {
        return a1.value < a2.value;
    });

    int i = 0, j = n - 1, found = 0;
    while(i < j) {
        if (v[i].value + v[j].value == p) {
            int mma = max(v[i].id,v[j].id);
            int mmi = min(v[i].id,v[j].id);
            cout << mmi << " " << mma << endl;
            found = 1;
            break;
        } else {
            if (v[i].value + v[j].value < p) {
                // increase i to increase value of the sum
                i++;
            } else {
                // decrease sum
                j--;
            }
        }
    }

    if (!found)
        cout << "IMPOSSIBLE\n";
   
    return 0;  
}
