#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n, k, p, cont;
    map<int,int>m;

    while(cin >> n >> k && n != 0 || k != 0) {
        cont = 0;
        m.clear();
        while(n--) {
            cin >> p;
            if(m.find(p) != m.end()) {
                m.at(p)++;
            } else {
                m.insert(make_pair(p,1));
            }
        }
        for ( auto i : m ) {
            if(i.second >= k)
                cont++;
        }
        cout << cont << endl;
    }
    return 0;
}
