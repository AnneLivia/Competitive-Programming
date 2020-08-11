#include <iostream>

using namespace std;

int main() {
    int n, m, im, jm, npos, posi, posj, mo, cont = 0;

    cin >> n >> m;
    cin >> im >> jm >> mo;
    posi = 0, posj = 0;
    while(mo--) {
        // 1 - north, 2 - south, 3 - east, 4 - west;
        cin >> npos;
        switch(npos) {
            case 1:
                posj++;
                break;
            case 2:
                posj--;
                break;
            case 3:
                posi++;
                break;
            case 4:
                posi--;
                break;
        }

        
        if (posi >= im-1 && posi <= im+1 &&
            posj >= jm-1 && posj <= jm+1) {
            cont++;
        }
    }

    cout << cont << endl;
    return 0;  
}
