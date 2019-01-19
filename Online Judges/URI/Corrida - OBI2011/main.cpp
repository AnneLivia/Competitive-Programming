#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    set<pair<int,int>>t;
    int n, qtdC,qtdV, soma, i, j = 1;
    cin >> qtdC >> qtdV;
    while(qtdC--) {
        soma = 0;
        i = 1;
        while(i <= qtdV) {
            cin >> n;
            soma+=n;
            i++;
        }
        t.insert(make_pair(soma,j++));
    }

    set<pair<int,int>>::iterator it = t.begin();
    for(i = 0; i < 3; i++) {
        cout << (it->second) << endl;
        it++;
    }

    return 0;
}
