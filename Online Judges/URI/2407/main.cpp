#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int ord, flag = false, sum1 = 0, sum2 = 0, sum3 = 0, magicSum;
    vector<vector<int>>v;
    vector<int> aux;

    cin >> ord;

    v.assign(ord,vector<int>());
    for ( int i = 0; i < ord; i++) {
        v[i].resize(ord);
    }
    int bigger = -1;
    for ( int i = 0; i < ord; i++) {
        for ( int j = 0; j < ord; j++) {
            cin >> v[i][j];
            if(v[i][j] > bigger)
                bigger = v[i][j];
        }
    }

    // Lines
    for(int i = 0; i < ord; i++) {
        sum1+=v[0][i];
        if(find(aux.begin(), aux.end(),v[0][i]) != aux.end()) {
            flag = true;
        } else {
            aux.push_back(v[0][i]);
        }
    }
    aux.clear();
    for(int i = 0; i < ord; i++) {
        sum2+=v[i][0];
        if(find(aux.begin(), aux.end(),v[i][0]) != aux.end()) {
            flag = true;
        } else {
            aux.push_back(v[i][0]);
        }
    }
    aux.clear();
    int j = ord - 1;
    for(int i = 0; i < ord; i++) {
        sum3+=v[j][i];
        if(find(aux.begin(), aux.end(),v[j][i]) != aux.end()) {
            flag = true;
        } else {
            aux.push_back(v[j][i]);
        }
        j--;
    }

    if (sum1 == sum2 && sum1 == sum3 && bigger <= (ord * ord) && !flag)
        cout << sum1 << endl;
    else
        cout << 0 << endl;
    return 0;
}
