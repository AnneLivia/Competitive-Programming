#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Player {
    string name;
    int point, colocation;
};

bool compare(const Player &a1, const Player &a2) {
    if(a1.point > a2.point)
        return true;
    else if (a1.point == a2.point) {
        if(a1.name < a2.name)
            return true;
    }
    return false;
}

int main()
{
    int j, bigger, lesser, point, soma, test = 1;
    string name;
    vector<Player>v;
    Player aux = {"",0};
    while(cin >> j && j != 0) {
        v.assign(j,aux);
        for ( int i = 0; i < j; i++) {
            soma = 0;
            bigger = -1; lesser = 10000; soma = 0;
            cin >> name;
            v[i].name = name;
            for ( int j = 0; j < 12; j++) {
                cin >> point;
                if(point > bigger)
                    bigger = point;
                if(point < lesser)
                    lesser = point;
                soma+=point;
            }
            soma-=(lesser+bigger);
            v[i].point = soma;
        }

        cout << "Teste " << test++ << endl;
        sort(v.begin(),v.end(),compare);
        int colocation = 1;
        for ( int i = 0; i < j; i++) {
            v[i].colocation = colocation;
            if(i != 0 && v[i].point == v[i - 1].point)
                v[i].colocation = v[i - 1].colocation;
            colocation++;
        }
        for ( int i = 0; i < j; i++) {
            cout << v[i].colocation << " " << v[i].point << " " << v[i].name << endl;
        }
        cout << endl;
    }
    return 0;
}
