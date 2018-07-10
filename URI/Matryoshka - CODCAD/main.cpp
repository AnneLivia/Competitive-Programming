#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back

using namespace std;

int main()
{
    int qtd, num, cont = 0;
    vector<int>values, orderValues, cv;
    cin >> qtd;
    while(qtd--) {
        cin >> num;
        values.pb(num);
        orderValues.pb(num);
    }
    sort(orderValues.begin(),orderValues.end());
    for(int i = 0; i < values.size(); i++) {
        if(values[i] != orderValues[i]) {
            cv.pb(values[i]);
            cont++;
        }
    }
    cout << cont << endl;
    sort(cv.begin(),cv.end());
    for(auto i : cv)
        cout << i << " ";
    cout << endl;
    return 0;
}
