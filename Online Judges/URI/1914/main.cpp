#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;

int main()
{
    char name[2][100], choose[2][6];
    int number[2], c;

    cin >> c;

    while(c--) {
        scanf(" %[^ ]",&name[0]);
        scanf(" %[^ ]",&choose[0]);
        scanf(" %[^ ]",&name[1]);
        scanf(" %[^\n]",&choose[1]);
        cin >> number[0] >> number[1];
        if(strcasecmp(choose[0],"PAR") == 0 && (number[0] + number[1]) % 2 == 0) {
            cout << name[0] << endl;
        } else if (strcasecmp(choose[0],"IMPAR") == 0 && (number[0] + number[1]) % 2 != 0) {
            cout << name[0] << endl;
        } else {
            cout << name[1] << endl;
        }


    }
    return 0;
}
