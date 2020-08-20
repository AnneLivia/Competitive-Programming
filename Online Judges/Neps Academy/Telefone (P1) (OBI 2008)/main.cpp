#include <iostream>
#include <map>

using namespace std;

char number(char c) {
    switch(c) {
        case '1': return '1';
            break;
        case '2':
        case 'A':
        case 'B':
        case 'C': return '2';
            break;
        case '3':
        case 'D':
        case 'E':
        case 'F': return '3';
            break;
        case '4':
        case 'G':
        case 'H':
        case 'I': return '4';
            break;
        case '5':
        case 'J':
        case 'K':
        case 'L': return '5';
            break;
        case '6':
        case 'M':
        case 'N':
        case 'O': return '6';
            break;
        case '7':
        case 'P':
        case 'Q':
        case 'R':
        case 'S': return '7';
            break;
        case '8':
        case 'T':
        case 'U':
        case 'V': return '8';
            break;
        case '9':
        case 'W':
        case 'X':
        case 'Y':
        case 'Z': return '9';
            break;
        case '0': return '0';
            break;
        default:
            return c;
    }
}

int main()
{
    string tel;
    cin >> tel;
    for (int i = 0; i < (int)tel.size(); i++) {
        cout << number(tel[i]);
    }
    cout << endl;
    return 0;
}
