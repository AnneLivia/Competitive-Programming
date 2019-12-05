#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>  > v(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    // line
    int suml = 0, sumc = 0, sq = 0, noline = 0, nocol = 0;
    for (int i = 0; i < n; i++) {
        suml = sumc = 0;
        for(int j = 0; j < n; j++) {
            suml+=v[i][j];
            sumc+=v[j][i];
        }
        if(sq == 0)
            sq = suml;
        if (suml != sq) {
            noline = 1;
            break;
        }
        if(sumc != sq) {
            nocol = 1;
            break;
        }
    }

    if(nocol || noline) {
        cout << "-1\n";
    } else {
        suml = 0, sumc = 0;
        int j = n - 1;
        int nodig1 = 0, nodig2 = 0;
        for (int i = 0; i < n; i++) {
            suml+=v[i][i];
            sumc+=v[i][j--];
        }
        if(suml != sq)
            nodig1 = 1;
        if(sumc != sq)
            nodig2 = 1;

        if(nodig1 || nodig2)
            cout << "-1\n";
        else
            cout << sq << endl;
    }
}
