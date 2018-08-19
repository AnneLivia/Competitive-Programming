#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    float f1, f2;
    double d1, d2;

    cin >> f1 >> f2 >> d1 >> d2;

    printf("A = %f, B = %f\n",f1,f2);
    printf("C = %f, D = %f\n",d1,d2);
    printf("A = %.1f, B = %.1f\n",f1,f2);
    printf("C = %.1f, D = %.1f\n",d1,d2);
    printf("A = %.2f, B = %.2f\n",f1,f2);
    printf("C = %.2f, D = %.2f\n",d1,d2);
    printf("A = %.3f, B = %.3f\n",f1,f2);
    printf("C = %.3f, D = %.3f\n",d1,d2);
    printf("A = %.3E, B = %.3E\n",f1,f2);
    printf("C = %.3E, D = %.3E\n",d1,d2);
    printf("A = %.0f, B = %.0f\n",f1,f2);
    printf("C = %.0f, D = %.0f\n",d1,d2);
    return 0;
}
