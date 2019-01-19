#include <iostream>

using namespace std;

void tolow(string& s) {
    for(int i = 0; i < (int)s.size(); i++)
        s[i] = tolower(s[i]);
}
int main()
{
    string s;
    while(getline(cin, s)) {
        tolow(s);
        if(s.compare("esquerda") == 0)
            cout << "ingles\n";
        else if (s == "direita")
            cout << "frances\n";
        else if (s == "nenhuma")
            cout << "portugues\n";
        else
            cout << "caiu\n";
    }
    return 0;
}
