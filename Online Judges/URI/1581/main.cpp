#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n, qp;
    set<string>pe;
    string aux;
    cin >> n;
    while(n--) {
        cin >> qp;
        pe.clear();
        while(qp--) {
            cin >> aux;
            pe.insert(aux);
        }
        if((int)pe.size() == 1)
            cout << *(pe.begin()) << endl;
        else
            cout << "ingles\n";
    }
    return 0;
}
