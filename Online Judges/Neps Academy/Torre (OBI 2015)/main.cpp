#include <iostream>
#include <vector>

using namespace std;

int main() {
    int d, sum = 0;

    cin >> d;

    vector<vector<int> > v(d, vector<int>(d, 0));

    vector<int>l(d, 0);
    vector<int>c(d, 0);

    for (int i = 0; i < d; i++) {
        for(int j = 0; j < d; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < d; i++) {
        for(int j = 0; j < d; j++) {
            l[i]+=v[i][j];
        }
    }

    for (int i = 0; i < d; i++) {
        for(int j = 0; j < d; j++) {
            c[i]+=v[j][i];
        }
    }

    for (int i = 0; i < d; i++) {
        for(int j = 0; j < d; j++) {
            int aux = (l[i] + c[j]) - (2 * v[i][j]);
            if(aux > sum) {
                sum = aux;
            }
        }
    }

    cout << sum << endl;
    return 0;
}
