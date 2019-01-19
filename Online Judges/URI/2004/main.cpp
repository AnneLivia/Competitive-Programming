#include <iostream>
#include <map>

using namespace std;

int main()
{
    int t, qtd, tipo, grama, soma;
    map<int,int>m;
    cin >> t;
    while(t--) {
        m.clear();
        soma = 0;
        cin >> qtd;
        while(qtd--) {
            cin >> tipo >> grama;
            if(m.find(tipo) != m.end()) {
                if(grama >= 10 && grama <= 100 && m.at(tipo) <= 100 && grama >= m.at(tipo)) {
                    m.at(tipo) = grama;
                } else if (grama >= 10 && grama <= 100 && m.at(tipo) > 100) {
                    m.at(tipo) = grama;
                } else if(grama > m.at(tipo) && !(m.at(tipo) >= 10 && m.at(tipo) <= 100)) {
                    m.at(tipo) = grama;
                }
            } else {
                m.insert(make_pair(tipo,grama));
            }
        }
        for(auto i : m) {
            soma+=i.second;
        }
        cout << soma << endl;
    }
    return 0;
}
