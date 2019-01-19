#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    string s, aux, rs;
    long int n[3];
    int j;
    while(cin >> s) {

        j = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            if(s[i] == '=')
                s[i] = '+';
        }

        stringstream split(s);

        while(getline(split,aux,'+')) {
            rs = "";

            for(int i = (int)aux.size() - 1; i >= 0; i--)
                rs+=aux[i];

            n[j++] = stoi(rs);
        }

        if(n[0] + n[1] == n[2])
            cout << "True\n";
        else
            cout << "False\n";

        if(s == "0+0+0")
            break;
    }
    return 0;
}
