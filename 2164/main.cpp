#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main()
{
    float n;
    cin >> n;
    printf("%.1f\n",(pow((1+sqrt(5))/2,n) - pow((1-sqrt(5))/2,n)) / sqrt(5));
    return 0;
}
