#include <iostream>

using namespace std;

struct Rect {
    int a, b;
};

int main() {
    Rect r1, r2, des; 
    bool ok = false;

    cin >> r1.a >> r1.b >> r2.a >> r2.b >> des.a >> des.b;
    
    if (r1.a >= des.b && r2.a >= des.b) {
        if (r1.a + r2.a >= des.b && r2.b + r1.b >= des.a) {
            ok = true;
        }
    } 
    
    if (r1.a >= des.a && r1.b >= des.b ||
        r1.b >= des.a && r1.a >= des.b ||
        r2.a >= des.a && r2.b >= des.b ||
        r2.b >= des.a && r2.a >= des.b) {
            ok = true;
    } else if (r1.a >= des.a && r2.a >= des.a) {
        if ((r1.a + r2.a) >= des.a && (r1.b + r2.b) >= des.b) {
            ok = true;
        } else if ((r1.a + r2.a) >= des.b && (r1.b + r2.b) >= des.a) {
            ok = true;
        }
    } else if (r1.a >= des.a && r2.b >= des.a) {
        if (r1.a + r2.b >= des.a && r1.b + r2.a >= des.b) {
             ok = true;
        }
    }  else if (r1.b >= des.a && r2.b >= des.a) {
        if ((r1.a + r2.a) >= des.b && (r1.b + r2.b) >= des.a) {
            ok = true;
        }
    } else if (r1.b >= des.a && r2.b >= des.a) {
        if (r1.b + r2.b >= des.a && r1.a + r2.a >= des.b) {
             ok = true;
        }
    } else if (r1.b >= des.a && r2.a >= des.a) {
        if (r1.b + r2.a >= des.a && r1.a + r2.b >= des.b) {
             ok = true;
        }
    } 

    if (ok)
        cout << "S\n";
    else
        cout << "N\n";

    return 0;  
}
