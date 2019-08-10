#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n, wrong = 0;
    string s;
    stack<char>sta;
    cin >> n;
    cin.ignore();
    while(n--) {
        getline(cin, s);
        for (int i = 0; i < (int)s.size(); i++) {
            if(s[i] == '{') {
                sta.push('{');
            } else if (s[i] == '}') {
                if(!sta.empty()) {
                    sta.pop();
                } else if (n == 0) {
                    wrong = 1;
                }
            }
        }
    }

    if(wrong || (int)sta.size() != 0)
        cout << "N\n";
    else
        cout << "S\n";
    return 0;
}
