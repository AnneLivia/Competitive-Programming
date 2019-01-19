#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    char words[50];
    int n,c, cont;
    cin >> n;
    while(n--) {
        scanf(" %[^\n]",words);
        cin >> c;
        for ( int i = 0; i < strlen(words); i++) {
            cont = 0;
            while(cont < c) {
                if(words[i] == 'A') {
                    words[i] = 'Z';
                    cont++;
                } else {
                    words[i] -=1;
                    cont++;
                }
            }
        }
        cout << words << endl;
    }
    return 0;
}
