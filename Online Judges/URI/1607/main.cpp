#include <iostream>

using namespace std;

int main()
{
    int t, cont, dis, disnet;
    string s1, s2;
    cin >> t;
    while(t--) {
        cont = 0;
        cin >> s1 >> s2;
        for ( int i = 0; i < (int)s1.size(); i++) {
            dis = 0;
            if((int)s1[i] > (int)s2[i]) {
                disnet = ((122 - (int)s1[i]) + (int)s1[i] - 97) - ((int)s1[i] - (int)s2[i]);
                dis+=disnet+1;
            } else
                dis = (int)s2[i] - (int)s1[i];

            cont+=dis;
        }
        cout << cont << endl;
    }
    return 0;
}
