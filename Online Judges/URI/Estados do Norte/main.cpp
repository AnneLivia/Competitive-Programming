#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string est;
    vector<string>norte = {
        "para",
        "roraima",
        "acre",
        "amapa",
        "amazonas",
        "rondonia",
        "tocantins",
    };
    getline(cin,est);
    if(find(norte.begin(),norte.end(),est) != norte.end()) {
        cout << "Regiao Norte\n";
    } else {
        cout << "Outra regiao\n";
    }
    return 0;
}
