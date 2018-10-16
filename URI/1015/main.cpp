#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main() {

    double x1,y1,x2,y2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;

    printf("%.4f\n",sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1))));
    return 0;
}
