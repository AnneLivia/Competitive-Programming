#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

void toup(string& s){
    for (int i = 0; i < (int)s.size(); i++) {
        s[i] = toupper(s[i]);
    }
}
int main()
{
    int nc, kids, ns;
    vector<string>aux;
    string wish, p;
    map<string,vector<string>>m;
    while(cin >> nc >> kids) {
        cin.ignore();
        m.clear();
        while(nc--) {
            getline(cin,wish);
            cin >> ns;
            cin.ignore();
            toup(wish);
            aux.clear();
            while(ns--) {
                getline(cin,p);
                toup(p);
                aux.push_back(p);
            }
            m.insert(make_pair(wish,aux));
        }

        while(kids--) {
            getline(cin,wish);
            toup(wish);
            stringstream split(wish);
            int second = 0;
            while(getline(split, p, ';')) {
                second++;
                if(second == 1) {
                    wish = p;
                } else {
                    if(find(m.at(wish).begin(), m.at(wish).end(), p) == m.at(wish).end()) {
                        cout << "N\n";
                    } else {
                        cout << "Y\n";
                    }
                }
            }
        }

    }
    return 0;
}
