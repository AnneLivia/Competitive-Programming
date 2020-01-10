#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int nn;
    cin >> nn;
    vector<vector<char > > t(nn, vector<char>(nn,' '));
    for (int i = 0; i < nn; i++) {
        for(int j = 0; j < nn; j++) {
            cin >> t[i][j];
        }
    }
    int tt, x1, x2, y1, y2;
    cin >> tt;
    while(tt--) {
        cin >> x1 >> y1 >> x2 >> y2;
        int co = 0;
        x1--; x2--;
        y1--; y2--;
        for (int i = x1; i <= x2; i++) {
            for(int j = y1; j <= y2; j++) {
                if(t[i][j] == 'F')
                    co++;
            }
        }
        cout << co << endl;
    }
    return 0;
}
