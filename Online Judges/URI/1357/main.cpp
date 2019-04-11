#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<vector<string> > v = {
        {{".*"}, {"**"}, {".."}}, // line 0, col (1,2,3) ...
        {{"*."}, {".."}, {".."}}, // line 1, col (1,2,3) ...
        {{"*."}, {"*."}, {".."}}, // line 2, col (1,2,3) ...
        {{"**"}, {".."}, {".."}}, // line 3, col (1,2,3) ...
        {{"**"}, {".*"}, {".."}}, // line 4, col (1,2,3) ...
        {{"*."}, {".*"}, {".."}}, // line 5, col (1,2,3) ...
        {{"**"}, {"*."}, {".."}}, // line 6, col (1,2,3) ...
        {{"**"}, {"**"}, {".."}}, // line 7, col (1,2,3) ...
        {{"*."}, {"**"}, {".."}}, // line 8, col (1,2,3) ...
        {{".*"}, {"*."}, {".."}} // line 9, col (1,2,3) ...
    };

    int digitos;
    char c, n;
    string br;
    vector<vector<string> > vs;
    while(cin >> digitos && digitos) {
        cin >> c;
        br = "";
        if(c == 'S') {
            while(digitos--) {
                cin >> n;
                br+=n;
            }

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < (int)br.size(); j++) {
                    if(j != 0)
                        cout << " ";
                    cout << v[(int)(br[j] - '0')][i];
                }
                cout << endl;
            }
        } else {
            vs.assign(digitos, vector<string>(3, ""));
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < digitos; j++) {
                    cin >> vs[j][i];
                }
            }
            for_each(vs.begin(), vs.end(), [&](vector<string> & vss) {
                for (int i = 0; i < 10; i++) {
                    if(vss[0] == v[i][0] && vss[1] == v[i][1] && vss[2] == v[i][2]) {
                        cout << i;
                    }
                }
            });
            cout << endl;
        }
    }
    return 0;
}
