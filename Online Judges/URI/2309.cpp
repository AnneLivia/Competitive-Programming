#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, a[3], b[3], qtd1, qtd2, total1 = 0, total2 = 0;
    map<int, int> cards = {{1,8}, 
                           {2,9},
                           {3,10},
                           {4,1},
                           {5,2},
                           {6,3},
                           {7,4},
                           {11,6},
                           {12,5},
                           {13,7}};
    cin >> n;
    while(n--) {
        qtd1 = qtd2 = 0;
        for(int i = 0; i < 3; i++)
            cin >> a[i];
        for(int i = 0; i < 3; i++)
            cin >> b[i];

        for(int i = 0; i < 3; i++) {
            if (cards.at(a[i]) >= cards.at(b[i])) {
                qtd1++;
            } else {
                qtd2++;
            }
        }
        if (qtd1 >= qtd2) {
            total1++;
        } else {
            total2++;
        }
    }    
    cout << total1 << " " << total2 << endl;
    return 0;  
}
