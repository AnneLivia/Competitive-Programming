#include <iostream>
#include <map>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int nle, nfr;
    char c1, c2, frase[100010];
    map<char,char>l;
    cin >> nle >> nfr;
    while(nle--) {
        cin >> c1 >> c2;
        l.insert(make_pair(c1,c2));
        l.insert(make_pair(c2,c1));
    }
    while(nfr--) {
        scanf(" %[^\n]", frase);
        for ( int i = 0; i < strlen(frase); i++) {
            if(l.find(frase[i]) != l.end())
                frase[i] = l.at(frase[i]);
        }
        cout << frase << endl;
    }
    return 0;
}
