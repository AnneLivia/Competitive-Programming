#include <iostream>
#include <map>

using namespace std;

int main() {
    int t, mm, n;
    map<string,string> m;
    string j, p, w;
    cin >> t;
    while(t--) {
        m.clear();
        cin >> mm >> n;
        while(mm--) {
            cin >> j;
            cin.ignore();
            getline(cin, p);
            m.insert({j,p});
        }

        while(n--) {
            int f = 0;
            getline(cin, w);
            w+=" "; p = "";
            for (int i = 0; i < (int)w.size(); i++) {
                if(w[i] != ' ') {
                    p+=w[i];
                } else {
                    if(f)
                        cout << " ";
                    f = 1;
                    if(m.find(p) != m.end()) {
                        cout << m[p];
                    } else {
                        cout << p;
                    }
                    p = "";
                }
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
