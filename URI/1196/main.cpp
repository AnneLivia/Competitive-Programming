#include <iostream>
#include "stdio.h"
using namespace std;

int main()
{

    for (int i = 1; i <= 9; i+=2)
    {
        int j = 7;
        while(j >= 5) {
            cout << "I="<<i<<" J="<<j<<endl;
            j--;
        }
    }
    return 0;
}
