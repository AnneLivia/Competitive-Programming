#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int nl;
    string n;
    stack<char>e;
    bool ok = true;
    cin >> nl;
    cin.ignore();
    while(nl--) {
        getline(cin,n);
        for ( int i = 0; i < (int)n.size(); i++) {
            if(n[i] == '{') {
                e.push('{');
            } else if (n[i] == '}') {
                if(e.empty()) {
                    ok = false;
                    break;
                } else {
                    e.pop();
                    ok = true;
                }
            }
        }
    }

    if(!e.empty())
        cout << "N\n";
    else if (ok)
        cout << "S\n";
    else
        cout << "N\n";
    return 0;
}
