#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string word, aux, r;
    int tam, j, found, cont;
    vector<string>v;
    while(cin >> word) {
        aux = "";
        v.clear();
        r = word;
        found = cont = 0;
        for(int i = (int)word.size() - 1; i >= 0; i--) {
            aux+=word[i];
            j = (int)r.size();
            while(j > i) {
                r.pop_back();
                j--;
            }

            tam = aux.size();
            j = (int)r.size() - tam;
            cont = 0;
            for(int k = tam - 1; k >= 0; k--) {
                if(aux[k] == r[j++]) {
                    cont++;
                }
            }

            if(cont == tam) {
                found = 1;
                v.push_back(r);
            }
        }
        if(!found)
            cout << word << endl;
        else {
            sort(v.begin(),v.end());
            for(int i = 0; i < (int)v.size(); i++)
                cout << v[i] << endl;
        }
    }
    return 0;
}
