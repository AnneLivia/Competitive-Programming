#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main() {

    string texto, outroTexto;
    vector<string>v;

    getline(cin,texto);

    texto+=" ";

    for ( int i = 0; i < (int)texto.size(); i++) {
        if(texto[i] != ' ')
            outroTexto+=texto[i];
        else {
            v.push_back(outroTexto);
            outroTexto = "";
        }
    }

    for ( int i = 0; i < (int)v.size(); i++) {
        if((int)v[i].size() >= 4) {
            if(v[i][0] == v[i][2] && v[i][1] == v[i][3]) {
                outroTexto+=v[i][2];
                outroTexto+=v[i][3];
                for ( int j = 4; j < (int)v[i].size(); j++) {
                    outroTexto+=v[i][j];
                }
            } else {
                for ( int j = 0; j < (int)v[i].size(); j++) {
                    outroTexto+=v[i][j];
                }
            }
        } else {
            for ( int j = 0; j < (int)v[i].size(); j++) {
                outroTexto+=v[i][j];
            }
        }

        outroTexto+=" ";
    }

    outroTexto.pop_back();
    cout << outroTexto << endl;

    return 0;
}
