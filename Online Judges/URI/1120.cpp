#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    char d;
    char c;

    while(cin >> d) {
       char ch;
       string s = "";
       bool previouswaszero = false;
       while (cin >> ch) {

          if (ch != d) {
            if (ch == '0' && !previouswaszero) {
                previouswaszero = true;
                s+=ch;
            } else if (ch != '0') {
                previouswaszero = false;
                s+=ch;
            }
          }

          if (cin.peek() == '\n')
            break;
       }

       if (s == "0" && d == '0')
            break;

        string c = "";
        if (s[0] == '0' && (int)s.size() >= 2) {
            for (int i = 1; i < (int)s.size(); i++) {
                c+=s[i];
            }
            s = c;
        }

        if (s == "")
            s = "0";
        cout << s << endl;
    }
}
