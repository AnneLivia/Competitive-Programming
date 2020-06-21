#include <iostream>

using namespace std;

int main() {
    int n, t, qtda, qtdb, qtdc, x;
    char op, in, to;    
    cin >> n >> t;
    qtda = qtdb = qtdc = n;
    while(t--) {
        cin >> op;
        if (op == 'A') {
            cin >> in >> to >> x;
            if (in == 'D') {
                qtda+=x;
                if (to == 'E') {
                    qtdb-=x;
                } else {
                    qtdc-=x;
                }
            } else if (in == 'E') {
                qtdb+=x;
                if (to == 'D') {
                    qtda-=x;
                } else {
                    qtdc-=x;
                }
            } else {
                qtdc+=x;
                if (to == 'D') {
                    qtda-=x;
                } else {
                    qtdb-=x;
                }
            }
        } else {
            cin >> in >> x;
            if(op == 'C') {
                if (in == 'D') {
                    qtda-=x;
                } else if (in == 'E') {
                    qtdb-=x;
                } else {
                    qtdc-=x;
                }
            } else if (op == 'V') {
                if (in == 'D') {
                    qtda+=x;
                } else if (in == 'E') {
                    qtdb+=x;
                } else {
                    qtdc+=x;
                }
            }
        }
    }
    cout << qtda << " " << qtdb << " " << qtdc << endl;
    return 0;  
}
