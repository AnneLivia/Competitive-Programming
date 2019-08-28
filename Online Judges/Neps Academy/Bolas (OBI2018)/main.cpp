#include <iostream>
#include <vector>

using namespace std;

ostream& operator << (ostream& ostr, const vector<int>& v) {
    for ( auto i : v ){
        ostr << i << " ";
    }
    return ostr;
}

int main()
{
    vector<int>v(8, 0), qtd(10, 0);
    for (int i = 0; i < 8; i++) {
        cin >> v[i];
    }
    int found = 1;
    for (int i = 0; i < 8; i++) {
        qtd[v[i]]++;
        if(qtd[v[i]] > 4) {
            found = 0;
            break;
        }
    }

    if(!found) {
        cout << "N\n";
    } else {
        cout << "S\n";
    }
    return 0;
}
