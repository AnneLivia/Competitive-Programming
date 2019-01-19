#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct C {
    int n, f;
    C() { this->f = 0; };
    C(const int& num) : n(num) {
    }
    bool operator() (const C& c1) {
        return (c1.n == this->n);
    }
};

bool compare(const C& c1, const C& c2) {
    if(c1.f < c2.f)
        return true;
    else if (c1.f == c2.f) {
        if(c1.n > c2.n)
            return true;
    }
    return false;
}

int main()
{
    vector<C>v;
    vector<C>::iterator it;
    string s;
    C aux;
    int j = 0;
    while(getline(cin,s)) {
        if(j != 0)
            cout << endl;
        v.clear();
        for(int i = 0; i < (int)s.size(); i++) {
            it = find_if(v.begin(),v.end(),C((int)s[i]));

            if(it != v.end()) {
                it->f++;
            } else {
                aux.f = 1; aux.n = (int)s[i];
                v.push_back(aux);
            }
        }
        sort(v.begin(),v.end(),compare);
        for(auto i : v) {
            cout << i.n << " " << i.f << endl;
        }
        j++;
    }
    return 0;
}
