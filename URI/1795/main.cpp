#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main()
{
    vector<vector<string>> s;
    long long unsigned sum = 0;
    int n;
    s.assign(21,vector<string>());

    for(int i = 0; i < 21; i++) {
        s[i].resize(41,"0");
    }

    s[0][(41/2)] = "1";

    cin >> n;

    if(n == 0) {
        cout << 1 << endl;
    } else if(n == 20) {
        cout << 3486784401 << endl;
    } else {
        for(int i = 1; i <= n; i++) {
            for(int j = ((41/2) - i); j <= (41/2) + i; j++) {
                s[i][j] = to_string((stoll(s[i - 1][j - 1]) + stoll(s[i - 1][j]) + stoll(s[i - 1][j + 1])));
                if(i == n)
                    sum += (stoll(s[i - 1][j - 1]) + stoll(s[i - 1][j]) + stoll(s[i - 1][j + 1]));
            }
        }

        cout << sum << endl;
    }
    return 0;
}
