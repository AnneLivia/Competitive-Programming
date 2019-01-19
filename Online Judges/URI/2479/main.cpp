#include <iostream>
#include <map>

using namespace std;

int main()
{
    string name;
    char sign;
    int amount, wentWell = 0, wentBad = 0;
    map<string,char>people;
    cin >> amount;

    while(amount--) {
        cin >> sign >> name;
        people.insert(make_pair(name,sign));
        if(sign == '+')
            wentWell+=1;
        else
            wentBad +=1;
    }
    for(auto i : people) {
        cout << i.first << endl;
    }
    cout << "Se comportaram: " << wentWell << " | Nao se comportaram: " << wentBad << endl;
    return 0;
}
