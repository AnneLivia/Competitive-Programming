#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<vector<int> > v;
    vector<int> coll, row;
    int n;

    cin >> n;
    v.assign(n, vector<int>(n, 0));
    coll.assign(n, 0);
    row.assign(n, 0);

    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    int biggest = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            coll[i]+=v[j][i];
            row[i]+=v[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            sum = coll[j] + row[i] - (2 * v[i][j]);
            if (sum > biggest)
                biggest = sum;
        }
    }

    cout << biggest << endl;
    return 0;
}
