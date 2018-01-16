#include <iostream>
#include <stdio.h>
using namespace std;

int main() {

     float A, B, C, per,areaT;
     cin >> A >> B >> C;
     if((A + B) > C && (A + C) > B && (B + C)>A){
         per = A + B + C;
         printf("Perimetro = %.1f\n",per);
     } else {
         areaT = ((A + B) * C) / 2;
         printf("Area = %.1f\n",areaT);
     }
    return 0;
}
