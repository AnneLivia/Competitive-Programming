#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int nPlayer, nJog, id, nPIsOn, vorf, answ, cont = 1;
    vector<int>v;
    vector<int>::iterator it;
    while(cin >> nPlayer >> nJog && nPlayer != 0 && nJog != 0) {
        v.clear();
        while(nPlayer--) {
            cin >> id;
            v.push_back(id);
        }
        while(nJog--) {
            cin >> nPIsOn >> vorf;
            it = v.begin();
            for(int i = 0; i < nPIsOn; i++) {
                cin >> answ;
                if(answ != vorf) {
                    v.erase(it);
                    it--;
                }
                it++;
            }
        }
        cout << "Teste " << cont++ << endl;
        for(vector<int>::iterator i = v.begin(); i < v.end(); i++)
            cout << *i << endl;
        cout << endl;
    }
    return 0;
}
