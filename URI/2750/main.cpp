#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n[16];
    for ( int i = 0; i < 16; i++)
        n[i] = i;
    cout << "---------------------------------------\n";
    cout << "|  decimal  |  octal  |  Hexadecimal  |\n";
    cout << "---------------------------------------\n";
    for(int i = 0; i < 16; i++) {
        printf("|     %2d    |   %2o    |       %X       |\n",n[i],n[i],n[i]);
    }
    cout << "---------------------------------------\n";

    return 0;
}
