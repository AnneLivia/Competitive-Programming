#include <iostream>
#include <string>

using namespace std;

int main()
{
    int c, power;
    string name;
    cin >> c;
    for ( int i = 0; i < c ; i++) {
        cin >> name >> power;
        if(name.compare("Thor") == 0)
            cout << "Y\n";
        else
            cout << "N\n";
    }

    return 0;
}
