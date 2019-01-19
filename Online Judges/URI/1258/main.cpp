#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Shirt {
    string color, owner;
    char s;
};

bool compare(const Shirt& s1, const Shirt& s2) {
    if(s1.color < s2.color) {
        return true;
    } else if (s1.color == s2.color) {
        if(s1.s > s2.s)
            return true;
        else if (s1.s == s2.s) {
            if(s1.owner < s2.owner)
                return true;
        }
    }
    return false;
}

int main()
{
    int n, j = 0;
    vector<Shirt>v;
    Shirt aux;
    while(cin >> n && n) {
        if(j != 0)
            cout << endl;
        v.clear();

        while(n--) {
           cin.ignore();
           getline(cin,aux.owner);
           cin >> aux.color >> aux.s;
           v.push_back(aux);
        }

        sort(v.begin(),v.end(),compare);
        for(auto i : v) {
            cout << i.color << " " << i.s << " " << i.owner << endl;
        }
        j++;
    }
    return 0;
}
