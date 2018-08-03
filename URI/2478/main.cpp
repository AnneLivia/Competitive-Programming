#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int p, x;
    string s, wish;
    vector<string>aux;
    map<string,vector<string>>m;

    while(cin >> p) {
        m.clear();
        while(p--) {
            aux.clear();
            x = 3;
            cin >> s;
            while(x--) {
                cin >> wish;
                aux.push_back(wish);
            }
            m.insert(make_pair(s,aux));
        }
        while(cin >> s >> wish) {
            if(m.find(s) != m.end()) {
                if (find(m.at(s).begin(), m.at(s).end(),wish) != m.at(s).end()) {
                    cout << "Uhul! Seu amigo secreto vai adorar o/\n";
                } else {
                    cout << "Tente Novamente!\n";
                }
            } else {
                cout << "Tente Novamente!\n";
            }
        }
    }
    return 0;
}
