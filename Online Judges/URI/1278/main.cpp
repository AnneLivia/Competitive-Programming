#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
    int n, ones, larger, first = 0;
    vector<string>v;
    string s, aux;

    while(cin >> n && n) {
        cin.ignore();
        v.clear();
        larger = 0;
        if(first)
            cout << endl;
        while(n--) {
            aux = "";
            ones = 0;
            getline(cin, s);
            for(int i = 0; i < (int)s.size(); i++) {
                if(s[i] != ' ') {
                    aux+=s[i];
                    ones = 0;
                } else {
                    if(!ones && aux != "") {
                        aux+=' ';
                        ones = 1;
                    }
                }
            }
            if(aux[(int)aux.size() - 1] == ' ')
                aux.pop_back();

            if((int)aux.size() > larger)
                larger = (int)aux.size();
            v.push_back(aux);
        }

        for(int i = 0; i < (int)v.size(); i++) {
            cout << setw(larger) << v[i] << endl;
        }

        first++;
    }
    return 0;
}
