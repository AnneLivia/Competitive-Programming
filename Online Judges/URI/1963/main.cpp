#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    double value1, value2;
    cin >> value1 >> value2;
    printf("%.2f%%\n",(value2/value1 - 1)* 100);
    return 0;
}
