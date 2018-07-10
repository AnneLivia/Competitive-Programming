#include <iostream>
#include <map>

using namespace std;

int main()
{
    int totalApp, totalEmpresa, total;
    long long unsigned t1,t2;
    map<long long unsigned int,long long unsigned int, std::greater<long long unsigned int>>programaMaquina, programaEmpresa, programaAlterado;
    cin >> totalApp >> totalEmpresa;
    total = totalApp;
    while(totalApp--) {
        cin >> t1 >> t2;
        if(programaMaquina.find(t1) != programaMaquina.end()) {
            if(programaMaquina[t1] < t2) {
                programaMaquina[t1] = t2;
            }
        } else
            programaMaquina.insert(make_pair(t1,t2));

    }
    while(totalEmpresa--) {
        cin >> t1 >> t2;
        programaEmpresa.insert(make_pair(t1,t2));
    }
    cout << endl;
    for(map<long long unsigned int,long long unsigned int>::iterator it = programaMaquina.begin(); it != programaMaquina.end(); it++) {
        if(programaEmpresa.find(it->first) != programaEmpresa.end()) {
            if(programaEmpresa[it->first] < it->second)
                programaAlterado[it->first] = it->second;
        }

    }

    cout << endl;
    for(map<long long unsigned int,long long unsigned int>::iterator it = programaAlterado.begin(); it != programaAlterado.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}
