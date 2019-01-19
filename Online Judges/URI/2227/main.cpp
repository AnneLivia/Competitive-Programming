#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main()
{
    int a,v, airport1,airport2, test = 1;
    while(true) {
        if(test > 1)
            cout << endl;
        cin >> a >> v;
        if(a == 0 && v == 0)
            break;

        list<int>graph[a];
        while(v--) {
            cin >> airport1 >> airport2;
            graph[airport1 - 1].push_back(airport2 - 1);
            graph[airport2 - 1].push_back(airport1 - 1);
        }
        int bigger = 0;
        cout << "Test " << test++ << endl;
        for(int i = 0; i < a; i++) {
            if(graph[i].size() > bigger)
                bigger = graph[i].size();
        }
        vector<int>getAirport;

        for(int i = 0; i < a; i++) {
            if(bigger == graph[i].size())
                getAirport.push_back(i + 1);
        }
        for(int i = 0; i < getAirport.size(); i++) {
            cout << getAirport[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
