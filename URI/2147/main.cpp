#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int t;
    char s[100000];
    cin >> t;
    for ( int i = 0; i < t; i++) {
        scanf(" %[^\n]",&s);
        printf("%.2f\n",(float)strlen(s)/100);
    }

    return 0;
}
