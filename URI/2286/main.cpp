#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t, n1, n2, teste = 1;
    vector<string>s;
    string name1, name2;
    while(cin >> t && t != 0) {
        s.clear();
        cin >> name1 >> name2;
        while(t--) {
            cin >> n1 >> n2;
            if((n1 + n2) % 2 == 0) {
                s.push_back(name1);
            } else {
                s.push_back(name2);
            }
        }
        cout << "Teste " << teste++ << endl;
        for(int i = 0; i < (int)s.size(); i++)
            cout << s[i] << endl;
        cout << endl;
    }
    return 0;
}
