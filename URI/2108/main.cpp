#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
    char str[200], *div, biggestWord[200];
    int i, maior = 0;
    while(true) {
        i = 0;
        scanf(" %[^\n]s",str);

        if(strcmp(str,"0") == 0)
            break;
        div = strtok(str," ");
        while(div != nullptr) {
            if(i != 0)
               cout << "-";
            cout << strlen(div);
            if(maior <= strlen(div)) {
                maior = strlen(div);
                strcpy(biggestWord,div);
            }
            div = strtok(nullptr," ");
            i++;
        }
        cout << endl;
    }

    cout << "\nThe biggest word: " << biggestWord << endl;
    return 0;
}
