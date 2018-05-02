#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t, n1, n2;
    string s, aux;
    cin >> t;
    while(t--) {
        s = "";
        cin >> n1 >> n2;
        for ( int i = n1; i <= n2 ; i++) {
            s+=to_string(i);
        }
        aux = s;
        for ( int i = (int)s.size() - 1; i >= 0 ; i--) {
            s+=aux[i];
        }
        cout << s << endl;
    }
    return 0;
}
