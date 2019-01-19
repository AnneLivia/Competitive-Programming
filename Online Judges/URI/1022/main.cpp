#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;
int mdc(int x, int y) {
    if(y == 0)
        return x;
    return mdc(y, (x % y));
}

int main()
{
    int t, num, den, j;
    string s, op;
    int v[4];

    cin >> t;
    while(t--) {
        j = 0;
        for (int i = 0; i < 7; i++) {
            cin >> s;
            if(s != "/" && s != "-" && s != "+" && s != "*")
                v[j++] = stoi(s);
            if (i == 3)
                op = s;
        }

        if(op.compare("+") == 0) {
            num = ((v[0] * v[3]) + (v[2] * v[1]));
            den = (v[1] * v[3]);
        } else if (op.compare("-") == 0) {
            num = ((v[0] * v[3]) - (v[2] * v[1]));
            den = (v[1] * v[3]);
        } else if (op.compare("*") == 0) {
            num = (v[0] * v[2]);
            den = (v[1] * v[3]);
        } else if (op.compare("/") == 0) {
            num = (v[0] * v[3]);
            den = (v[2] * v[1]);
        }

        int div = abs(mdc(num, den));
        cout << num << "/" << den << " = " << (num/div) << "/" << (den/div) << endl;
    }
    return 0;
}
