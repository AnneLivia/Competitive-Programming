#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    int qtP, cont = 0;
    set<string>pokes;
    string namePok, aux = "";
    cin >> qtP;
    getchar();
    while(qtP--) {
        getline(cin,namePok);
        pokes.insert(namePok);
    }

    cout << "Falta(m) " << 151 - pokes.size() << " pomekon(s).\n";
    return 0;
}
