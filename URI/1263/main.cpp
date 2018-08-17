#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    int qtd, ct;
    vector<string>v;
    string s, aux;
    while(getline(cin,s)) {
        qtd = ct = 0;
        v.clear();
        stringstream split(s);
        while(split >> aux)
            v.push_back(aux);
        v.push_back("-1");
        char c = v[0][0];
        for(int i = 0; i < (int)v.size(); i++) {
            if(tolower(c) == tolower(v[i][0])) {
                ct++;
            } else {
                c = v[i][0];
                if(ct >= 2)
                    qtd++;
                ct = 1;
            }
        }
        cout << qtd << endl;
    }
    return 0;
}
