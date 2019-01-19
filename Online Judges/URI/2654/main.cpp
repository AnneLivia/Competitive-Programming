#include <iostream>
#include <algorithm>


using namespace std;

typedef struct {
    string n;
    int p, ma, mo;
} god;

bool comp(const god& a,const god& b) {
    if(a.p > b.p) {
        return true;
    } else if (a.p == b.p) {
        if(a.ma > b.ma) {
            return true;
        } else if (a.ma== b.ma) {
            if(a.mo < b.mo) {
                return true;
            } else if (a.mo == b.mo) {
                if(a.n.compare(b.n) < 0)
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    god g[10010];
    int tam, p, ma, mo;
    string n;

    cin >> tam;
    for ( int i = 0; i < tam; i++) {
        cin >> n >> p >> ma >> mo;
        g[i].n = n; g[i].p = p; g[i].ma = ma; g[i].mo = mo;
    }

    sort(g, g+tam, comp);
    cout << g[0].n << endl;
    return 0;
}
