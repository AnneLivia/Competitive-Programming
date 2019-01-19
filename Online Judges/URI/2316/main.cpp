#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

struct Car {
    int id, currentCheck, nTurn, last;
};

bool compare(const Car& c1, const Car& c2) {
    if(c1.nTurn > c2.nTurn)
        return true;
    else if (c1.nTurn == c2.nTurn) {
        if(c1.currentCheck > c2.currentCheck)
            return true;
        else if (c1.currentCheck == c2.currentCheck) {
            if(c1.last < c2.last)
                return true;
        }
    }
    return false;
}

int main() {
    int k, n, m, car, check;
    vector<Car>c;

    cin >> k >> n >> m; // k (check points) n (cars) m (sensors)

    c.assign(n, Car());

    for (int i = 0; i < n; i++) {
        c[i].id = i + 1;
        c[i].currentCheck = c[i].nTurn = 0;
    }

    for (int i = 0; i < m; i++) {
        cin >> car >> check;
        if(c[car - 1].currentCheck + 1 == check) {
            c[car - 1].currentCheck = check;
            c[car - 1].last = i + 1;
        } else if(c[car - 1].currentCheck == k && check == 1) {
            c[car - 1].nTurn++;
            c[car - 1].currentCheck = check;
            c[car - 1].last = i + 1;
        }
    }



    sort(c.begin(), c.end(), compare);

    for (int i = 0; i < n; i++) {
        if(i != 0)
            cout << " ";
        cout << c[i].id;
    }

    cout << endl;
    return 0;
}
