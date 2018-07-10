#include <iostream>

using namespace std;

int main()
{
    int hOut, tTravel, hour, sum;

    cin >> hOut >> tTravel >> hour;

    sum = hOut + tTravel;
    if(sum > 24) {
        sum = sum - 24;
    } else if (sum == 24) {
        sum = 0;
    }
    sum += hour;
    if(sum < 0) {
        sum +=24;
    }
    cout << sum << endl;

    return 0;
}
