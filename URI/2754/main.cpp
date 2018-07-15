#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    double d1, d2;
    d1 = 234.345;
    d2 = 45.698;
    printf("%.6f - %.6f\n",d1,d2);
    printf("%.0f - %.0f\n",d1,d2);
    printf("%.1f - %.1f\n",d1,d2);
    printf("%.2f - %.2f\n",d1,d2);
    printf("%.3f - %.3f\n",d1,d2);
    printf("%e - %e\n",d1,d2);
    printf("%E - %E\n",d1,d2);
    printf("%g - %g\n",d1,d2);
    printf("%g - %g\n",d1,d2);

    return 0;
}
