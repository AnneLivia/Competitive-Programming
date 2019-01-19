#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
/*
    strtok = split string into tokens
    char * strtok ( char * str, const char * delimiters );

*/
int main()
{
    string s, k[4];
    int j = 0;
    cin >> s;
    for(int i = 0; i < (int)s.size(); i++)
    {
        if(s[i] != '.' && s[i] != '-')
            k[j]+=s[i];
        else
            j++;
    }

    for ( int i = 0; i < 4; i++) {
        cout << k[i] << endl;
    }

/*
    char c[50];
    char* pc;
    scanf("%s",c);
    pc = strtok(c,".-"); // I put the c string and the delimiters that I don't want to be part of the program
    while(pc != nullptr) {
        printf("%s\n",pc);
        pc = strtok(nullptr,".-");
    }
*/
    return 0;
}
