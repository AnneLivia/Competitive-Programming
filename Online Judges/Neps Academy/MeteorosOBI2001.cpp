#include <iostream>

using namespace std;

struct Farm {
    int x1, y1, x2, y2;
};

/*
    x1 y1 --------------- 
        |
        |
        |
        ------------------
                        x2, y2;
*/


int main() {
    Farm f;
    int n, a, b, cont, t = 1;

    while(cin >> f.x1 >> f.y1 >> f.x2 >> f.y2 && 
        f.x1 + f.x2 + f.y1 + f.y2 != 0) {
        cin >> n;

        // fixing rectangle
        if (f.x2 > f.x1) {
            swap(f.x1, f.x2);
        }

        if (f.y2 > f.y1) {
            swap(f.y1, f.y1);
        }
        
        cont = 0;
        cout << "Teste " << t++ << endl;
        while(n--) {
            cin >> a >> b;
            if ((a >= f.x1 && a <= f.x2 && 
                b >= f.y1 && b <= f.y2) ||
                (a <= f.x1 && a >= f.x2 && 
                b <= f.y1 && b >= f.y2)) {
                cont++;
            }
        }
        cout << cont << "\n\n";
    }
    return 0;  
}
