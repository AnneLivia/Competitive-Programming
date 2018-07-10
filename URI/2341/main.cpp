#include <iostream>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    int qtd, n, bcd, i = 1;
    map<int,int>en;
    set<int>v;
    cin >> qtd >> bcd;

    while(i <= bcd) {
        en.insert(make_pair(i,0));
        i++;
    }

    while(qtd--) {
        cin >> n;
        en.at(n)++;
    }

    for(auto i : en)
        v.insert(i.second);
    set<int>::iterator it = v.begin();
    cout << *it << endl;
    return 0;
}
