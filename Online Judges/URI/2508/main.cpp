#include <iostream>
#include <string>

using namespace std;

int getN(const char l) {
    int n = 0;
    switch(l) {
        case 'A':
        case 'J':
        case 'S': n = 1;
                  break;
        case 'B':
        case 'K':
        case 'T': n = 2;
                  break;
        case 'C':
        case 'L':
        case 'U': n = 3;
                  break;
        case 'D':
        case 'M':
        case 'V': n = 4;
                  break;
        case 'E':
        case 'N':
        case 'W': n = 5;
                  break;
        case 'F':
        case 'O':
        case 'X': n = 6;
                  break;
        case 'G':
        case 'P':
        case 'Y': n = 7;
                  break;
        case 'H':
        case 'Q':
        case 'Z': n = 8;
                  break;
        case 'I':
        case 'R': n = 9;
                  break;
    }

    return n;
}

void number(string n) {
    int auxI = 0;
    for ( int i = 0; i < (int)n.size(); i++) {
        auxI+= n[i] - '0';
    }

    string aux = to_string(auxI);

    if((int)aux.size() > 1)
        number(aux);
    else {
        cout << auxI << endl;
    }
}

int main()
{
    string name;
    int n;
    while(getline(cin,name)) {
        n = 0;
        for ( int i = 0; i < (int)name.size(); i++) {
            n += getN(toupper(name[i]));
        }

        name = to_string(n);
        number(name);
    }
    return 0;
}
