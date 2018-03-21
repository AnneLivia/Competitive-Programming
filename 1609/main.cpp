#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<long int>c;
    long int id;
    int qT, qC;
    cin >> qT;
    while(qT--) {
        c.clear();
        cin >> qC;
        while(qC--) {
            cin >> id;
            c.insert(id);
        }
        cout << c.size() << endl;
    }
    return 0;
}
