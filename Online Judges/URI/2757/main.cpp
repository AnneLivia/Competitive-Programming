#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    printf("A = %d, B = %d, C = %d\n",a,b,c);
    printf("A = %10d, B = %10d, C = %10d\n",a,b,c);
    printf("A = %010d, B = %010d, C = %010d\n",a,b,c);
    printf("A = %-10d, B = %-10d, C = %-10d\n",a,b,c);
    return 0;
}
