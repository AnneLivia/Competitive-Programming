#include <iostream>
#include "stdio.h"
using namespace std;

int main()
{
    float vet[6];
    int nPos = 0;
    float media = 0;
    for(int i = 0; i < 6; i++) {
        cin >> vet[i];
        if(vet[i] >= 0) {
            nPos +=1;
            media = vet[i] + media;
        }
    }

    media = media / nPos;

    printf("%d valores positivos\n",nPos);
    printf("%.1f\n",media);
    return 0;
}
