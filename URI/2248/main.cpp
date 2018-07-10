#include <iostream>
#include <vector>

using namespace std;

struct aluno {
    int cod, nota;
};

int main()
{
    int t, contt = 1, bigger;
    vector<aluno>v;
    aluno aux;

    while(cin >> t && t != 0) {
        v.clear();
        bigger = -1;
        while(t--) {
            cin >> aux.cod >> aux.nota;
            v.push_back(aux);
            if(aux.nota > bigger)
                bigger = aux.nota;
        }
        cout << "Turma " << contt++ << endl;
        for(int i = 0; i < (int) v.size(); i++) {
            if(v[i].nota == bigger)
                cout << v[i].cod << " ";
        }
        cout << endl << endl;
    }
    return 0;
}
