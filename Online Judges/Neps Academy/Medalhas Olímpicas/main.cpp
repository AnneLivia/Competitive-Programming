#include <iostream>
#include <algorithm>

using namespace std;

struct op {
    int pa, id, br, ou;

    bool operator < (const op& a) {
        if (this->ou > a.ou) {
            return true;
        } else if (this->ou == a.ou) {
            if (this->pa > a.pa)
                return true;
            else if (this->pa == a.pa)
                return this->br > a.br;
        }
        return false;
    }
};

int main()
{
    op v[2];

    for (int i = 0; i < 2; i++) {
        cin >> v[i].ou >> v[i].pa >> v[i].br;
        v[i].id = i;
    }

    sort(v, v+2);

    cout << (char)(v[0].id+'A') << endl;

    return 0;
}
