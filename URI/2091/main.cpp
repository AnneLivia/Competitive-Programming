#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n;
    string k;
    map<string,int>m;
    while(cin >> n && n) {
        m.clear();
        while(n--) {
            cin >> k;
            if(m.find(k) != m.end())
                m.at(k)++;
            else
                m.insert(make_pair(k,1));
        }

        for(auto i : m) {
            if((i.second & 1) == 1) {
                cout << i.first << endl;
                break;
            }
        }
    }
    return 0;
}
