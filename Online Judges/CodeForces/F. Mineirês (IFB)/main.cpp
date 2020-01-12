#include <iostream>
#include <map>

using namespace std;

int main()
{
    string sete, s1, s2;
    map<string, string> d;
    int w, c;
    cin >> w >> c;
    cin.ignore();
    for (int i = 0; i <  w; i++) {
        getline(cin, s1);
        getline(cin, s2);
        d.insert({s1, s2});
    }

    for (int i = 0; i < c; i++) {
        getline(cin, sete);
        sete+=' ';
        string aux = "";
        int f = 0;
        for(int j = 0; j < (int)sete.size(); j++) {
            if(sete[j] != ' ') {
                aux+=sete[j];
            } else {
                if(f != 0) {
                    cout << " ";
                }
                    f++;
                if(d.find(aux) != d.end()) {
                    cout << d[aux];
                } else {
                    cout << aux;
                }
                aux = "";
            }
        }
        cout << endl;
    }

    return 0;
}
