#include <iostream>

using namespace std;

int main()
{
    int t, g, k;
    cin >> t;
    while(t--) {
        cin >> g >> k;
        if(g < k) {
            cout << g << endl;
        } else {
            int qtd = g / k;
            cout << ((g - (qtd * k)) + qtd) << endl;
        }
    }
    return 0;
}
