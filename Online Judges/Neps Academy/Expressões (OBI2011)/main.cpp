#include <iostream>
#include <stack>

using namespace std;

int main() {

    int n;
    string c;
    cin >> n;
    while(n--) {
        stack<char>s;
        cin >> c;
        bool ok = false;
        for (int i = 0; i < (int)c.size(); i++) {
            ok = false;
            if(c[i] == '(' || c[i] == '{' || c[i] == '[')
                s.push(c[i]);
            else {
                if(s.empty()) {
                    ok = false;
                    break;
                }
                char top = s.top();
                if(c[i] == ')' && top == '(') {
                    ok = true;
                } else if (c[i] == ']' && top == '[')  {
                    ok = true;
                } else if (c[i] == '}' && top == '{') {
                    ok = true;
                } else {
                    ok = false;
                    break;
                }

                if(ok)
                    s.pop();
            }
        }
        if(ok && s.empty()) {
            cout << "S\n";
        } else {
            cout << "N\n";
        }
    }
    return 0;
}
