#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Gift {
    string name;
    int preference;
    double price;
};

bool compare(const Gift& g1, const Gift& g2) {
    if(g1.preference > g2.preference)
        return true;
    else if (g1.preference == g2.preference) {
        if(g1.price < g2.price)
            return true;
        else if (g1.price == g2.price) {
            if(g1.name < g2.name)
                return true;
        }
    }
    return false;
}

int main()
{
    vector<Gift>w;
    Gift aux;
    string name;
    int qtd;
    while(cin >> name >> qtd) {
        w.clear();
        cin.ignore();
        while(qtd--) {
            getline(cin, aux.name);
            cin >> aux.price >> aux.preference;
            w.push_back(aux);
            cin.ignore();
        }
        sort(w.begin(),w.end(),compare);
        cout << "Lista de " << name << endl;
        cout.precision(2);
        cout.setf(ios::fixed);
        for(int j = 0; j < (int)w.size(); j++) {
                cout << w[j].name << " - R$" << w[j].price << endl;
        }
        cout << endl;
    }
    return 0;
}
