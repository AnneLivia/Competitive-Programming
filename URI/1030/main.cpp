#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int nc, qtdp, qtd1, qtds, s, cas = 1, only1, indv;
    vector<int>v;
    cin >> nc;
    while(nc--) {
        cin >> qtdp >> s;
        v.assign(qtdp,1);
        only1 = 0;

        if(qtdp == 1) {
            indv = 1;
        } else {
            int i = qtdp - 1;

            while(only1 != qtdp - 1) {
                qtd1 = qtds = 0;

                while(qtds < s) {
                    if(i + 1 == qtdp)
                        i = -1;

                    if(v[++i] == 1) {
                        qtds++;
                    }
                }
                v[i] = 0;

                only1++;
            }

            for (int i = 0; i < qtdp; i++) {
                if(v[i] == 1)
                    indv = i + 1;
            }
        }
        cout << "Case " << cas++ << ": " << indv << endl;
    }
    return 0;
}
