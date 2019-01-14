#include <iostream>
#include <vector>

using namespace std;

vector<int>w, val;

int dp(int wc) {
    vector<vector<int>>table;
    int s = (int)val.size();
    table.assign(s + 1, vector<int>());

    for(int i = 0; i < s + 1; i++)
        table[i].resize(wc + 1);

    for(int i = 1; i < s + 1; i++) {
        for (int j = 1; j < wc + 1; j++) {
            if(w[i - 1] <= j) {
                table[i][j] = max(table[i - 1][j], table[i - 1][j - w[i - 1]] + val[i - 1]);
            } else {
                table[i][j] = table[i - 1][j];
            }
        }
    }
    return table[s][wc];
}

int main()
{
    int t, a, wc, valc, n;

    cin >> t;
    while(t--) {
        cin >> a;
        w.assign(a, 0);
        val.assign(a, 0);
        for (int i = 0; i < a; i++) {
            cin >> val[i] >> w[i];
        }
        cin >> wc >> valc;
        if(dp(wc) >= valc)
            cout << "Missao completada com sucesso\n";
        else
            cout << "Falha na missao\n";
    }
    return 0;
}
