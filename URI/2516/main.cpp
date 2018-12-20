#include <iostream>
#include <vector>

using namespace std;

string dpc(char c, int qtd) {
    string aux = "";
    for(int i = 0; i < qtd; i++)
        aux+=c;
    return aux;
}

int main()
{
    int x, y, p, q;
    vector<string>v, res;
    string str;

    while(cin >> x >> y && x && y) {
        v.clear(); res.clear();
        for(int i = 0; i < x; i++) {
            cin >> str;
            v.push_back(str);
        }
        cin >> p >> q;
        string aux;
        for(int i = 0; i < x; i++) {
            aux = "";
            for(int j = 0; j < y; j++) {
                aux+=dpc(v[i][j],q/y);
            }
            for (int j = 0; j < p/x; j++) {
                res.push_back(aux);
            }
        }

        for (int i = 0; i < (int)res.size(); i++) {
            cout << res[i] << endl;
        }

        cout << endl;
    }
    return 0;
}
