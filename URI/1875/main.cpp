#include <iostream>

using namespace std;

int main()
{
    int t, r, g, b, ng;
    char s1, s2;
    cin >> t;
    while(t--) {
        cin >> ng;
        r = g = b = 0;
        while(ng--) {
            cin >> s1 >> s2;
            if(s1 == 'G' && s2 == 'R' ||
               s1 == 'G' && s2 == 'B') {
                if(s2 == 'B')
                    g+=2;
                else
                    g++;
            }
            if(s1 == 'R' && s2 == 'G' ||
               s1 == 'R' && s2 == 'B')
               if(s2 == 'G')
                    r+=2;
               else
                    r++;
            if(s1 == 'B' && s2 == 'R' ||
               s1 == 'B' && s2 == 'G')
                if(s2 == 'R')
                    b+=2;
                else
                    b++;
        }
        if (g > r && g > b)
            cout << "green\n";
        else if (r > g && r > b)
            cout << "red\n";
        else if (b > g && b > r)
            cout << "blue\n";
        else if(g == b && g == r) {
            cout << "trempate\n";
        } else if (g == b && g != r || g == r && g != b || r == b && r != g) {
            cout << "empate\n";
        }
    }
    return 0;
}
