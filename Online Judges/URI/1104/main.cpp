#include <iostream>
#include <set>

using namespace std;

int main()
{
    int na, nb, n, tam;
    set<int>al,be,cards;
    while(true) {
        al.clear();
        be.clear();
        cards.clear();

        cin >> na >> nb;
        if(na == 0 && nb == 0)
            break;

        while(na--) {
            cin >> n;
            al.insert(n);
        }

        while(nb--) {
            cin >> n;
            be.insert(n);
        }


        if((int)al.size() < (int)be.size()) {
            for(auto i : al) {
                if(be.find(i) == be.end())
                    cards.insert(i);
            }
        } else {
            for(auto i : be) {
                if(al.find(i) == al.end())
                    cards.insert(i);
            }
        }

        cout << (int)cards.size() << endl;
    }
    return 0;
}
