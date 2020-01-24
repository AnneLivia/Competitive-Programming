#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

struct Ol {
    int o, p, b, id;
    /*
    bool operator<(const Ol& a2) {
        if(this->o > a2.o)
            return true;
        else if (this->o == a2.o) {
            if(this->p > a2.p)
                return true;
            else if (this->p == a2.p){
                if(this->b > a2.b)
                    return true;
                else if (this->b == a2.b) {
                    if(this->id < a2.id) {
                        return true;
                    }
                }
            }
         }
        return false;
    }
    */
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<Ol>v(n, Ol{0,0,0, 0});

    for (int i = 0; i < n; i++) {
        v[i].id=i+1;
    }

    int o, p, b;
    for (int i = 0; i < m; i++) {
        cin >> o >> p >> b;
        v[o - 1].o++;
        v[p - 1].p++;
        v[b - 1].b++;
    }

    sort(v.begin(), v.end(), [](const Ol& a1, const Ol& a2) -> bool{
        if(a1.o > a2.o)
            return true;
        else if (a1.o == a2.o) {
            if(a1.p > a2.p)
                return true;
            else if (a1.p == a2.p){
                if(a1.b > a2.b)
                    return true;
                else if (a1.b == a2.b) {
                    if(a1.id < a2.id) {
                        return true;
                    }
                }
            }
         }
        return false;
    });

    for (int i = 0; i < n; i++) {
        if(i != 0)
           cout << " ";
        cout << v[i].id;
    }
    cout << endl;
    return 0;
}
