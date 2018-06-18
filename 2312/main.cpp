#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Country {
    int p, b, o;
    string name;
};

bool compare(const Country&c1,const Country&c2) {
    bool yes = false;
    if(c1.o > c2.o) {
        yes = true;
    } else if (c1.o == c2.o) {
        if (c1.p > c2.p)
            yes = true;
        else if (c1.p == c2.p) {
            if (c1.b > c2.b) {
                yes = true;
            } else if (c1.b == c2.b) {
                if (c1.name < c2.name)
                    yes = true;
            }
        }
    }
    return yes;
}

int main()
{
    int n, o, p, b;
    string cName;
    vector<Country>c; Country aux;

    cin >> n;
    while(n--) {
        cin >> cName >> o >> p >> b;
        aux.name = cName; aux.b = b; aux.p = p; aux.o = o;
        c.push_back(aux);
    }

    sort(c.begin(),c.end(),compare);

    for ( int i = 0; i < (int)c.size(); i++) {
        cout << c[i].name << " " << c[i].o << " " << c[i].p << " " << c[i].b << endl;
    }

    return 0;
}
