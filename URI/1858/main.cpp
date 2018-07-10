#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, nPeople, lesser = 0, pos = 0;
    vector <int> tPeople;
    cin >> n;
    while(n--) {
        cin >> nPeople;
        tPeople.push_back(nPeople);
    }
    lesser = tPeople[0];
    for (int i = 0; i < tPeople.size(); i++) {
        if(tPeople[i] < lesser) {
            lesser = tPeople[i];
            pos = i;
        }
    }

    cout << ++pos << endl;
    return 0;
}
