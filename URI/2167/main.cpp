#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int qtd, n, aux, i;
    bool flag = false;
    vector<int>v;
    cin >> qtd;
    while(qtd--) {
        cin >> n;
        v.push_back(n);
    }

    aux = v[0];
    for( i = 1; i < (int) v.size(); i++) {
        if(aux <= v[i])
            aux = v[i];
        else {
            flag = true;
            break;
        }
    }

    if(flag)
        cout << ++i << endl;
    else
        cout << "0\n";
    return 0;
}
