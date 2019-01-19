#include <iostream>

using namespace std;

int main()
{
    string a, b;
    int t, flag;
    cin >> t;
    while(t--) {
        flag = 0;
        cin >> a >> b;
        if((int)a.size() >= (int)b.size()) {
            for(int i = (int)a.size() - 1, j = (int) b.size() - 1; j >= 0; i--, j--) {
                if(a[i] != b[j]) {
                    flag = 1;
                    break;
                }
            }
            if(flag)
                cout << "nao encaixa\n";
            else
                cout << "encaixa\n";
        } else {
            cout << "nao encaixa\n";
        }
    }
    return 0;
}
