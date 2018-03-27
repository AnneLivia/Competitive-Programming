#include <iostream>
#include <set>

using namespace std;

int main()
{

    int qtd, va;
    set<pair<int,string>>co;
    string name;

    while(cin >> qtd) {
        co.clear();
        while(qtd--) {
            cin >> name >> va;
            co.insert(make_pair(va,name));
        }
        set<pair<int,string>>::iterator it;
        for(it = co.begin(); it != co.end(); it++) {
            if(it != co.begin())
                cout << " ";
            cout << it->second;
        }
        cout << endl;
    }
    return 0;
}
