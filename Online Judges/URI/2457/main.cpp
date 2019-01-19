#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    char c;
    string s, aux = "";
    int contW, contT;
    contW = contT = 0;

    cin >> c;
    cin.ignore();
    getline(cin, s);
    s+=' ';
    for ( int i = 0; i < (int)s.size(); i++) {
        if(s[i] != ' ') {
            aux +=s[i];
        } else {
            if(find(aux.begin(),aux.end(),c) != aux.end())
                contT++;
            aux = "";
            contW++;
        }
    }

    cout.precision(1);
    cout.setf(ios::fixed);
    cout << (float)contT / contW * 100 << endl;
    return 0;
}
