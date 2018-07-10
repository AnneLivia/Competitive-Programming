#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int qtdPeople, qtdPeopleLeft, id;
    vector<int>identifier;
    cin >> qtdPeople; // Amount of people on the queue
    while(qtdPeople--) {
        cin >> id;
        identifier.push_back(id);
    }
    cin >> qtdPeopleLeft; // People who left the queue
    while(qtdPeopleLeft--) {
        cin >> id;
        vector<int>::iterator it;
        it = find(identifier.begin(),identifier.end(),id);
        if(it != identifier.end()) {
            identifier.erase(it);
        }
    }

    for(vector<int>::iterator it = identifier.begin(); it < identifier.end(); it++) {
        cout << *it;
        if(it < identifier.end() - 1)
            cout << " ";
    }
    cout << endl;
    return 0;
}
