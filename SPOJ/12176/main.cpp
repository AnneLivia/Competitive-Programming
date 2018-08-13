#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t, n1, n2, sw;
    vector<vector<char>>ans;
    cin >> t;
    while(t--) {
        cin >> n1 >> n2;
        ans.clear();
        ans.assign(n1,vector<char>());
        for(int i = 0; i < n1; i++)
            ans[i].resize(n2);
        sw = 1;
        for(int i = 0; i < n1; i++) {
            for(int j = 0; j < n2; j++) {
                if(i == 0) {
                    if(sw) {
                        ans[i][j] = '*';
                        sw = 0;
                    } else {
                        ans[i][j] = '.';
                        sw = 1;
                    }
                } else {
                    if(ans[i - 1][j] == '*') {
                        ans[i][j] = '.';
                    } else {
                        ans[i][j] = '*';
                    }
                }
            }
        }

        for (int i = 0; i < n1; i++) {
            for(int j = 0; j < n2; j++) {
                cout << ans[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
