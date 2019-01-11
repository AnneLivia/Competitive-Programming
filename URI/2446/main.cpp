#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

bool problem(int change, int coins) {
    vector<vector<int> > table;
    table.assign(coins + 1, vector<int>());
    for (int i = 0; i < (int)v.size() + 1; i++) {
        table[i].resize(change + 1);
    }

    table[0][0] = 1;
    for (int i = 1; i < coins + 1; i++) {
        for(int j = 0; j < change + 1; j++) {
            if(j == 0)
                table[i][j] = 1; // First column is all 1
            else {
                if(table[i - 1][j])
                    table[i][j] = 1;
                else if(j - v[i - 1] >= 0) {
                    if(table[i - 1][j - v[i - 1]])
                        table[i][j] = 1;
                }
            }
        }
    }


    return table[coins][change];
}

int main() {
    int change, n, coins;
    cin >> change >> coins;
    for (int i = 0; i < coins; i++) {
        cin >> n;
        v.push_back(n);
    }

    if(problem(change, coins))
        cout << "S\n";
    else
        cout << "N\n";

    return 0;
}
