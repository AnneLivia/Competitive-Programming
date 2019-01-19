#include <iostream>

using namespace std;

int main()
{
    int n;
    string resp, aux, s;
    cin >> n;
    cin.ignore();
    while(n--) {
        getline(cin,s);
        aux = resp = "";
        s+=" ";
        for(int i = 0; i < (int)s.size(); i++) {
            if(s[i] != ' ') {
                aux+=s[i];
            } else {
                if(aux != "") {
                    resp+=aux[0];
                    aux = "";

                }
            }
        }
        cout << resp << endl;
    }
    return 0;
}
