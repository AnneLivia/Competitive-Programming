#include <iostream>

using namespace std;

int main()
{
    int n[2], dis[2], vel[2];
    cin >> n[0] >> dis[0] >> vel[0];
    cin >> n[1] >> dis[1] >> vel[1];

    if((double)dis[0] / vel[0] < (double)dis[1] / vel[1])
        cout << n[0] << endl;
    else
        cout << n[1] << endl;
    return 0;
}
