#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int qtd, n, aux;
    bool flag = false, valley, control = false;
    // When the second value is greater than the last one, it's a peak, other than that it's a valley

    vector<int>v;

    cin >> qtd;

    while(qtd--) {
        cin >> n;
        v.push_back(n);
    }

    aux = v[0];

    for(int i = 1 ; i < (int)v.size(); i++) {
        if(i == 1) {
            if(aux < v[i]) {
                valley = true;
            } else
                valley = false;
        }

        if(aux < v[i] && valley) {
            aux = v[i];
            valley = false;
        } else if (aux > v[i] && !valley) {
            aux = v[i];
            valley = true;
        } else {
            flag = true;
            break;
        }
    }

    if(!flag)
        cout << "1\n";
    else
        cout << "0\n";

    return 0;
}
