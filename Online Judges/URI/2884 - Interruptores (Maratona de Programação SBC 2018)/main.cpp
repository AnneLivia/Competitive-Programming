#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int nLamp, nInte, qtdAsc, n, qtdCon;

    vector<vector<int>>inte;
    vector<int>lamp;

    cin >> nInte >> nLamp;

    lamp.assign(nLamp, 0);
    inte.assign(nInte, vector<int>());

    cin >> qtdAsc;
    for(int i = 0; i < qtdAsc; i++) {
        cin >> n;
        lamp[n - 1] = 1;
    }

    for(int i = 0; i < nInte; i++) {
        cin >> qtdCon;
        while(qtdCon--) {
            cin >> n;
            inte[i].push_back(n);
        }
    }

    int j = 0, contAp, contAc, no = 0, cont = 0;
    while(true) {
        contAp = contAc = 0;
        for(int i = 0; i < (int)inte[j].size(); i++) {
            lamp[inte[j][i] - 1] = !lamp[inte[j][i] - 1];
        }
        cont++;
        for(int i = 0; i < (int)lamp.size(); i++) {
            if(lamp[i])
                contAc++;
            else
                contAp++;
        }

        j++;

        if(contAp == lamp.size())
            break;

        if(j == inte.size()) {
            if(contAc == qtdAsc) {
                no = 1;
                break;
            } else {
                j = 0;
            }
        }

    }

    if(!no) {
        cout << cont << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}
