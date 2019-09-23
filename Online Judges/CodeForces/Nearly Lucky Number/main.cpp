#include <iostream>

using namespace std;

int main()
{
    string n;
    cin >> n;
    int nlucky = 0;
    for (int i = 0; i < (int)n.size(); i++) {
        if(n[i] == '4' || n[i] == '7') {
            nlucky++;
        }
    }
    string test = to_string(nlucky);

    nlucky = 0;

    for (int i = 0; i < (int)test.size(); i++) {
        if(test[i] == '4' || test[i] == '7') {
            nlucky++;
        }
    }

    if(nlucky == (int)test.size()) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}
