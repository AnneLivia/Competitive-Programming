#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// Must finish later
int main()
{
    long int vertices, arestas, mayorOrSec, city1,city2;
    bool yes;
    cin >> vertices >> arestas;
    vector<long int>city[vertices];
    while(arestas--) {
        cin >> mayorOrSec >> city1 >> city2;
        city1--;
        city2--;
        yes = false;

        if(mayorOrSec == 1) { // Secretary adding a bridge
            city[city1].push_back(city2);
            city[city2].push_back(city1);
        } else { // Mayor asking if there is a bridge linking the cities
            for(int i = 0; i < city[city1].size(); i++)
            {
                if(city[city1][i] == city2) {
                    yes = true;
                    break;
                }
            }
            if(yes)
                cout << "1\n";
            else
                cout << "0\n";
        }
    }
    return 0;
}
