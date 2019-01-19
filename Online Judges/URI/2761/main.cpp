#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    float r;
    char c;
    char s[100];
    scanf("%d %f %c",&n,&r,&c);
    scanf(" %[^\n]",s);
    printf("%d%.6f%c%s\n",n,r,c,s);
    printf("%d\t%.6f\t%c\t%s\n",n,r,c,s);
    printf("%10d%10.6f%10c%10s\n",n,r,c,s);
    return 0;
}
