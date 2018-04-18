#include <iostream>
#include <cstring>
#include <bitset>

using namespace std;

int main()
{
    long long int t, c, i;
    string s, aux;
    scanf("%lld",&t);
    while(t--) {
        i = 0;
        cin >> s;
        scanf("%lld",&c); // To increase performance
        while(c && s[i]) {
            if((c & 1) == 0) {
                c >>= 1;
                i++;
            } else {
                if(s[i] == 'X') {
                    s[i] = 'O';
                    c>>=1;
                } else {
                    s[i] = 'X';
                    c = (c>>=1)+1;
                }
                i++;
            }
        }
        cout << s << endl;
    }
    return 0;
}
