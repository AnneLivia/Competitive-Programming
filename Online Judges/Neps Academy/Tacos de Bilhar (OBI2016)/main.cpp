#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    long long int n, c, fab = 0;

    cin >> n;
    map<long long int, int> tacos;

    while(n--) {
        cin >> c;
        if(tacos.find(c) != tacos.end()) {
           if(tacos.at(c) == 0) {
                fab+=2;
                tacos.at(c) = 1;
           } else {
               tacos.at(c) = 0;
           }
        } else {
            tacos.insert({c, 1});
            fab+=2;
        }
    }

    cout << fab << endl;
    return 0;
}
