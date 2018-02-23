#include <iostream>
#include <map>

using namespace std;

int main()
{
    int cTeste, n;
    map<int,int>howManyTimes;
    cin >> cTeste;
    while(cTeste--) {
        cin >> n;
        if(howManyTimes.find(n) == howManyTimes.end()) {
            howManyTimes.insert(make_pair(n,1));
        } else {
            howManyTimes.at(n) +=1;
        }
    }
    for(auto i : howManyTimes) {
        cout << i.first << " aparece " << i.second << " vez(es)\n";
    }
    return 0;
}
