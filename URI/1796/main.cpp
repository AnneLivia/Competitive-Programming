#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int numberOfPeople, opnion;
    stack<int>no,yes;
    cin >> numberOfPeople;
    while(numberOfPeople--) {
        cin >> opnion;
        if(!opnion)
            yes.push(opnion);
        else
            no.push(opnion);
    }

    if(yes.size() > no.size())
        cout << "Y\n";
    else
        cout << "N\n";
    return 0;
}
