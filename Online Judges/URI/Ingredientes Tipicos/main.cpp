#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int n, m, k; string nomeingr, nomeporc;
    vector<string>ingred, aux, noporcAux, tipica;
    map<string,vector<string> >porcao;

    cin >> n;
    for ( int i = 0; i < n; i++) {
        cin >> nomeingr;
        ingred.push_back(nomeingr);
    }

    cin >> m;

    for ( int i = 0; i < m; i++) {
        aux.clear();
        cin >> nomeporc >> k;
        porcao.insert(make_pair(nomeporc,aux));
        noporcAux.push_back(nomeporc);
        while(k--) {
            cin >> nomeingr;
            aux.push_back(nomeingr);
        }
        porcao.at(nomeporc) = aux;
    }



    map<string,vector<string> >::iterator it, help;

    int qtdIngr, cont;
    for( it = porcao.begin(); it != porcao.end(); it++) {
        qtdIngr = 0;
        for(int i = 0; i < (int)it->second.size(); i++) {
            if(find(ingred.begin(),ingred.end(),it->second[i]) != ingred.end())
                qtdIngr++;
            else {
                cont = 0;
                bool found = false;
                bool nentrou = false;
                help = porcao.find(it->second[i]);
                while(!found && !nentrou) {
                    if (help != porcao.end()) {
                        for ( int j = 0; j < (int)help->second.size(); j++) {
                            if(find(ingred.begin(),ingred.end(),help->second[j]) != ingred.end())
                                cont++;
                            else {
                                help = porcao.find(help->second[j]);
                                if(help != porcao.end()) {
                                    nentrou = false;
                                    cont = 0;
                                    break;
                                }
                            }
                            if(j == (int)help->second.size() - 1) {
                                found = true;
                                nentrou = true;
                            }
                        }
                        if(cont > (int)(help->second.size() / 2))
                            qtdIngr++;
                    } else {
                        found = true;
                        nentrou = true;
                    }
                }
            }
        }
        if(qtdIngr > (int)(it->second.size() / 2))
            tipica.push_back(it->first);
    }

    for ( int i = 0; i < m; i++) {
        if(find(tipica.begin(),tipica.end(),noporcAux[i]) != tipica.end())
            cout << "porcao tipica\n";
        else
            cout << "porcao comum\n";
    }


    return 0;
}
