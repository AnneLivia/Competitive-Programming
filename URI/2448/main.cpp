#include <iostream>
#include <vector>

using namespace std;

int binario(int valor, int ini, int fim, vector<int>ca) {
    int meio = 0;
    fim -=1;
    while(ini <= fim)
    {
        meio = ( ini + fim ) / 2;
        if(valor < ca[meio])
            fim = meio - 1;
        else{
            if(valor > ca[meio])
                ini = meio + 1;
            else
                return meio;
        }
    }
}

int main()
{
    int n, m, v, cont = 0, merEnt = 0;
    vector<int>ca,mer;
    cin >> n >> m;

    while(n--) {
        cin >> v;
        ca.push_back(v);
    }

    while(m--) {
        cin >> v;
        mer.push_back(v);
    }
    int indAnt = 0;
    for(int i = 0; i < (int)mer.size(); i++) {

        int ind = binario(mer[i],0,(int)ca.size(),ca);
        cont += abs(indAnt - ind);

        indAnt = ind;


        /*if(mer[merEnt] > ca[i]) {
            i++;
            cont++;

        } else if (mer[merEnt] < ca[i]) {
            i--;
            cont++;

        } else {
            merEnt++;
        }

        if(merEnt == (int)mer.size())
            break;*/
    }

    cout << cont << endl;

    return 0;
}
