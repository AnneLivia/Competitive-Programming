#include <iostream>
#include <vector>

using namespace std;

int main() {
    int j, r, c, cont, inde = 0;

    cin >> j >> r;
    vector<int>v(j, 0);
    for(int i = 0; i < r; i++) {
        for (int jj = 0; jj < j; jj++)  {
            cin >> c;
            v[jj]+=c;
        }
    }

    int maxx = 0, index = 0;;

    for (int i = 0; i < j; i++) {
        if (maxx <= v[i]) {
            maxx = v[i];
            index = i;
        }
    }

    cout << index + 1 << endl;
}
