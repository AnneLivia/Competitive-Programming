#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<string>s;
    string j;
    while(getline(cin,j)) {
        s.insert(j);
    }

    cout << (int)s.size() << endl;
    return 0;
}
