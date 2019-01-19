#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int t, contline, contMat, contCol, ins = 0;
    vector<string>v;
    vector<int>aux;
    string auxText, auxText2;
    cin >> t;

    while(t--) {
        contline = contMat = contCol = 0;
        v.assign(9, "");
        aux.assign(9, 0);
        for (int i = 0; i < 9; i++) {
            auxText = auxText2 = "";
            for(int j = 0; j < 9; j++) {
                cin >> aux[j];
                auxText2+= (aux[j] + '0');
            }

            v[i] = auxText2;
            sort(aux.begin(), aux.end());

            for (int i = 0; i < 9; i++) {
                auxText+=(aux[i] + '0');
            }


            if(auxText == "123456789") {
                contline++;
            }
        }

        int k;
        for(int i = 0; i < 9; i++) {
            auxText = "";
            k = 0;
            for(int j = 0; j < 9; j++) {
                aux[k++] = v[j][i] - '0';
            }
            sort(aux.begin(), aux.end());
            for(int j = 0; j < 9; j++)
                auxText+=(aux[j]+'0');
            if(auxText == "123456789")
                contCol++;
        }

        for (int i = 0; i < 9; i+=3) {
            for(int j = 0; j < 9; j+=3) {
                auxText = "";

                aux[0] = v[i][j] - '0';
                aux[1] = v[i][j + 1] - '0';
                aux[2] = v[i][j + 2] - '0';
                aux[3] = v[i + 1][j] - '0';
                aux[4] = v[i + 1][j + 1] - '0';
                aux[5] = v[i + 1][j + 2] - '0';
                aux[6] = v[i + 2][j] - '0';
                aux[7] = v[i + 2][j + 1] - '0';
                aux[8] = v[i + 2][j + 2] - '0';

                sort(aux.begin(), aux.end());

                for (int k = 0; k < 9; k++) {
                    auxText+=(aux[k] + '0');
                }

                if(auxText == "123456789") {
                    contMat++;
                }
            }
        }

        cout << "Instancia " << ++ins << endl;
        if(contline == 9 && contMat == 9 && contCol == 9) {
            cout << "SIM\n";
        } else {
            cout << "NAO\n";
        }
        cout << endl;
    }
    return 0;
}
