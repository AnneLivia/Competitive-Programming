#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int qtd, n1, n2, n3, id, i, r;
    string name;
    vector<string>wrong;
    vector<pair<pair<int,int>,int>>e;
    char op;
    bool im;
    while(cin >> qtd) {
        i = 0;
        im = false;
        e.clear();
        wrong.clear();
        while(i < qtd) {
            cin >> n1 >> n2 >> op >> n3;
            e.push_back(make_pair(make_pair(n1,n2),n3));
            i++;
        }
        i = 0;
        while(i < qtd) {
            cin >> name >> id >> op;
            if(op == '+')
                r = e[id - 1].first.first + e[id - 1].first.second;
            else if (op == '-')
                r = e[id - 1].first.first - e[id - 1].first.second;
            else if (op == '*')
                r = e[id - 1].first.first * e[id - 1].first.second;
            else if (op == 'I')
                im = true;

            if(!im && r != e[id - 1].second)
                wrong.push_back(name);
            else if (im) {
                int auxS = e[id - 1].first.first + e[id - 1].first.second;
                int auxSu = e[id - 1].first.first - e[id - 1].first.second;
                int auxM = e[id - 1].first.first * e[id - 1].first.second;

                if(auxS == e[id - 1].second || auxSu == e[id - 1].second || auxM == e[id - 1].second) {
                    wrong.push_back(name);
                }
            }

            im = false;
            i++;
        }
        sort(wrong.begin(),wrong.end());

        if((int)wrong.size() == qtd)
            cout << "None Shall Pass!\n";
        else if (wrong.empty())
            cout << "You Shall All Pass!\n";
        else {
            for(int i = 0; i < (int)wrong.size(); i++) {
                if(i != 0)
                    cout << " ";
                cout << wrong[i];
            }
            cout << endl;
        }
    }

    return 0;
}
