#include <iostream>
#include <string>

using namespace std;

bool vowel(char c) {
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    return false;
}

int main()
{
    string line, aux1 = "", aux2 = "";
    cin >> line;
    for ( int i = 0; i < (int)line.size(); i++) {
        if(vowel(line[i])) {
            aux1+=line[i];
        }
    }

     for ( int i = (int)line.size() - 1; i >= 0; i--) {
        if(vowel(line[i])) {
            aux2+=line[i];
        }
    }

    if(aux1.compare(aux2) == 0)
        cout << "S\n";
    else
        cout << "N\n";
    return 0;
}
