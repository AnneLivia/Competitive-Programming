#include <iostream>
#include <algorithm>

using namespace std;
// must finish
int main()
{
    int q, n, k, j, me, ma, vez, counter, vet[101];
    cin >> q;
    while(q--) {
        cin >> n;
        j = me = counter = 0;
        for(int i = 0; i < n; i++) {
            cin >> k;
            if(k % 2 != 0)
                vet[j++] = k;
        }
        if(j != 0) {
            ma = j - 1;
            vez = 1;
            sort(vet,vet+j);
            while(counter < j) {
                if(counter != 0)
                    cout << " ";
                if(vez) {
                    cout << vet[ma--];
                    vez = 0;
                    counter++;
                } else {
                    cout << vet[me++];
                    vez = 1;
                    counter++;
                }
            }
            cout << endl;
        }
    }
    cout << endl;
    return 0;
}
