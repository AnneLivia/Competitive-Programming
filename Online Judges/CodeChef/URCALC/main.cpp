#include <iostream>

using namespace std;

int main()
{
    int n1, n2;
    string c, s;
    cin >> n1 >> n2 >> c;
    if(c == "+")
        cout << n1 + n2 << endl;
    else if (c == "-")
        cout << n1 - n2 << endl;
    else if (c == "*")
        cout << n1 * n2 << endl;
    else if (c == "/") {
        s = to_string((double) n1 / n2);
        int cont = 0, ja = 0;
        for(int i = 0; i < (int)s.size(); i++) {
            if(s[i] == '.')
                ja = 1;
            else {
                if(ja) {
                    if(s[i] == '0')
                        cont++;
                }
            }
        }
        if(cont == 6)
            cout.precision(1);
        cout.setf(ios::fixed);
        cout << (double) n1 / n2 << endl;
    }
    return 0;
}
