#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Rena {
    string name;
    int peso, idade;
    float altura;
};

bool compare(Rena& r1, Rena& r2) {
    if(r1.peso > r2.peso)
        return true;
    else if (r1.peso == r2.peso) {
        if(r1.idade < r2.idade) {
            return true;
        } else if (r1.idade == r2.idade) {
            if(r1.altura < r2.altura)
                return true;
            else if (r1.altura == r2.altura) {
                if(r1.name < r2.name)
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    int t, qtdrenas, renas, i = 1;
    vector<Rena>r;
    Rena aux;
    cin >> t;
    cin.ignore();
    while(t--) {
        r.clear();
        cin >> qtdrenas >> renas;
        while(qtdrenas--) {
            cin >> aux.name >> aux.peso >> aux.idade >> aux.altura;
            r.push_back(aux);
        }
        sort(r.begin(),r.end(),compare);

        cout << "CENARIO {" << i++ << "}\n";
        for(int j = 0; j < renas; j++) {
            cout << j + 1 << " - " << r[j].name << endl;
        }
    }
    return 0;
}
