#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <sstream>

using namespace std;

bool compare(const string& b1, const string& b2) {
    return ((int)b1.size() > (int)b2.size());
}

int main()
{
    vector<string>v;
    int qtd;
    string s, aux;
    scanf("%d",&qtd);
    getchar();
    while(qtd--) {
        v.clear();
        getline(cin,s);
        stringstream split(s);
        while(split >> aux)
            v.push_back(aux);

        stable_sort(v.begin(),v.end(),compare);

        for (int i = 0; i < (int)v.size(); i++) {
            if(i != 0)
                cout << " ";
            cout << v[i];
        }
        cout << endl;
    }
    return 0;
}
