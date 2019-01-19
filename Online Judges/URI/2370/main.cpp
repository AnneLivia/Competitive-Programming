#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;
bool compare(const pair<int,string>&i, const pair<int,string>&j)
{
    return i.second > j.second;
}

int main()
{
    int qtdStudent, qtdTeams, level, contTeam = 0;
    string name;
    vector<pair<int,string>>person;

    cin >> qtdStudent >> qtdTeams;
    while(qtdStudent--) {
        cin >> name >> level;
        person.push_back(make_pair(level,name));
    }
    sort(person.rbegin(),person.rend()); // Sorting the vector values
    list<pair<int,string>>teams[qtdTeams];
    for(auto i : person) {
        teams[contTeam].push_front(i);
        contTeam++;
        if(contTeam == qtdTeams) {
            contTeam = 0;
        }
    }

    for(int i = 0; i < qtdTeams; i++) {
        teams[i].sort(compare);
        cout << "Time " << i+1 << endl;
        while(!teams[i].empty()) {
            cout << teams[i].back().second << endl;
            teams[i].pop_back();
        }
        cout << endl;
    }

    return 0;
}
