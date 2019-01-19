#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int t, cont;
    string d;
    cin >> t;
    cin.ignore();
    while(t--) {
        cont = 0;
        stack<char>di;
        getline(cin,d);
        for(int i = 0; i < (int)d.size(); i++) {
            if(d[i] == '<') {
                di.push('<');
            } else if (d[i] == '>') {
                if(!di.empty()) {
                    cont++;
                    di.pop();
                }
            }
        }

        cout << cont << endl;
    }
    return 0;
}
