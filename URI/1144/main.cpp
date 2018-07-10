#include <iostream>
#include "stdio.h"
#include "math.h"
using namespace std;

int main()
{

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int aux = 0;
        while(aux < 2)
        {
            if(aux == 0)
                printf("%d %d %d\n",i,i*i,i*i*i);
            else
                printf("%d %d %d\n",i,i*i+1,i*i*i+1);
            aux++;
        }
    }
    return 0;
}
