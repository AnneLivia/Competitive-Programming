#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a,b;
    while(cin >> a >> b) {
        if(a.find(b) != string::npos) {
            cout << "Resistente\n";
        } else {
            cout << "Nao resistente\n";
        }
    }
    return 0;
}
