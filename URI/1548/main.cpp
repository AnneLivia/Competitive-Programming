#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int cTeste, qtdAlunos, nota, contMov;
    cin >> cTeste;
    while(cTeste--) {
        cin >> qtdAlunos;
        vector<int>notasMat;
        vector<int>orderNotasMat;

        while(qtdAlunos--) {
            cin >> nota;
            notasMat.push_back(nota);
            orderNotasMat.push_back(nota);
        }
        contMov = 0;
        sort(orderNotasMat.begin(),orderNotasMat.end(),greater<int>());

        for(int i = 0; i < orderNotasMat.size(); i++) {
            if(orderNotasMat[i] == notasMat[i])
                contMov++;
        }
        cout << contMov << endl;
    }
    return 0;
}
