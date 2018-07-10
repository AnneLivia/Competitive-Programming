#include <iostream>
#include <list>

using namespace std;
ostream& operator<<(ostream& ostr, list<int>& l) {
    for(auto i = l.begin(); i != l.end(); i++) {
        ostr << *i << endl;
    }
    return ostr;
}

bool decs(int a, int b) {
    return a > b;
}

int main()
{
    int qtd, n;
    cin >> qtd;

    list<int>par,inpar;

    while(qtd--) {
        cin >> n;
        if(n % 2 == 0) {
            par.push_front(n);
        } else {
            inpar.push_back(n);
        }
    }
    par.sort();
    inpar.sort(decs);
    cout << par << inpar;
    return 0;
}
