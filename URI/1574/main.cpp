#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int t, pos, ins;
    string aux;
    vector<string>v;
    cin >> t;
    while(t--) {
        v.clear();
        cin >> ins;
        cin.ignore();
        pos = 0;
        while(ins--) {
            getline(cin,aux);
            v.push_back(aux);
            if(aux.compare("LEFT") == 0) {
                pos--;
            }
            else if(aux.compare("RIGHT") == 0) {
                pos++;
            } else {
                string copie = "";
                int n;
                for(int i = 8; i < (int)aux.size(); i++)
                    copie+=aux[i];
                n = stoi(copie);
                if(v[n - 1].compare("RIGHT") == 0) {
                    pos++;
                    v[(int)v.size() - 1] = "RIGHT";
                } else if (v[n - 1].compare("LEFT") == 0) {
                    pos--;
                    v[(int)v.size() - 1] = "LEFT";
                }
            }
        }
        cout << pos << endl;
    }
    return 0;
}
