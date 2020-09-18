#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Data {
    int n, qtd;
};

int main() {
    int n, t = 1, va;
    vector<Data>mm;
    cin >> n;
    while(n--) {
        mm.clear();
        for(int i = 0; i < 5; i++) {
            cin >> va;
            
            vector<Data>::iterator it = find_if(mm.begin(), mm.end(), [&va](const Data& d1) -> bool {
                return d1.n == va;
            });
            
            if (it != mm.end()) {
                it->qtd++;
            } else {
                mm.push_back({va, 1});
            }
        }

        sort(mm.begin(), mm.end(), [](const Data& d1, const Data& d2) -> bool {
            return d1.n < d2.n;
        });

        int point = 0;

        if ((int)mm.size() == 5) {
            bool sequence = true;
            for (int i = 1; i < 5; i++) {
                if (mm[i].n != mm[i - 1].n + 1) {
                    sequence = false;
                } 
            }    
            if (sequence) {
                point = mm[0].n + 200;
            }
        } else if ((int)mm.size() == 2) {
            if (mm[0].qtd == 4)
                point = mm[0].n + 180;
            else if (mm[1].qtd == 4) {
                point = mm[1].n + 180;
            } else if (mm[0].qtd == 3 && mm[1].qtd == 2) {
                point = mm[0].n + 160;
            } else if (mm[0].qtd == 2 && mm[1].qtd == 3) {
                point = mm[1].n + 160;
            }
        } else if ((int)mm.size() == 3) {
            if (mm[0].qtd == 3) {
                point = mm[0].n + 140;
            } else if (mm[1].qtd == 3) {
                point = mm[1].n + 140;
            } else if (mm[2].qtd == 3) {
                point = mm[2].n + 140;
            } else if (mm[0].qtd == 2 && mm[1].qtd == 2) {
                point = mm[1].n * 3 + mm[0].n * 2 + 20;
            } else if (mm[0].qtd == 2 && mm[2].qtd == 2) {
                point = mm[2].n * 3 + mm[0].n * 2 + 20;
            } else if (mm[1].qtd == 2 && mm[2].qtd == 2) {
                point = mm[2].n * 3 + mm[1].n * 2 + 20;
            } 
        } else if ((int)mm.size() == 4) {
            for (int i = 0; i < 4; i++) {
                if (mm[i].qtd == 2) {
                    point = mm[i].n;
                    break;
                } 
            }
        }

        cout << "Teste " << t++ << "\n";
        cout << point << "\n\n";
    }
    return 0;  
}
