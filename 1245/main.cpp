#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int qtd, ns, cont;
    char ls;
    vector<pair<int,char>>p;
    vector<pair<int,char>>::iterator it;
    bool flag;
    while(cin >> qtd) {
        cont = 0;
        flag = false;
        p.clear();
        while(qtd--) {
            cin >> ns >> ls;
            if(p.empty()) {
                p.push_back(make_pair(ns,ls));
            } else {
               for(it = p.begin(); it < p.end(); it++) {
                 if(it->first == ns && it->second != ls) {
                   flag = true;
                   break;
                 }
               }
               if(flag) {
                cont++;
                p.erase(it);
                flag = false;
               } else {
                p.push_back(make_pair(ns,ls));
               }
            }
        }

        cout << cont << endl;
    }
    return 0;
}
