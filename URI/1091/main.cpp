#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int c, caso = 1, f, m, pi, snI;
    string inf, sn;
    char g;

    vector<pair<int,char>>sap;
    while(cin >> c) {
        sap.clear();
        cin.ignore();
        f = m = pi = 0;
        g = ' ';
        sn = "";
        getline(cin,inf);
        inf += " ";
        for(int i = 0; i < inf.length(); i++) {
            if(inf[i] != ' ' && inf[i] != 'F' && inf[i] != 'M')
                sn = sn + inf[i];
            else if(inf[i] != ' ' && inf[i] == 'F' || inf[i] == 'M')
                g = inf[i];

            if(inf[i] == ' ' && g != ' ') {
                snI = stoi(sn);
                sap.push_back(make_pair(snI,g));
                sn = "";
                g = ' ';
            }
        }

        for(auto i : sap) {
            if(i.first == c) {
                pi++;
                if(i.second == 'F')
                    f++;
                else
                    m++;
            }
        }
        if(caso != 1)
            cout << endl;
        cout << "Caso " << caso << ":" << endl;
        cout << "Pares Iguais: " << pi << endl;
        cout << "F: " << f << endl;
        cout << "M: " << m << endl;
        caso++;
    }
    return 0;
}
