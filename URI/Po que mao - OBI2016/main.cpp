#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int dd, x,y,z, soma = 0, cont = 0;
    vector<int>d;
    cin >> dd >> x >> y >> z;
    d.push_back(x);
    d.push_back(y);
    d.push_back(z);

    sort(d.begin(),d.end());

    for(int i = 0; i < 3; i++) {
        soma = d[i] + soma;
        if(soma <= dd)
            cont++;
    }
    cout << cont << endl;
    return 0;
}
