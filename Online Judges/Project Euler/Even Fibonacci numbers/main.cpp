#include <iostream>

using namespace std;

int main()
{
    int sum = 0, current = 1, previous = 0;

    while(current <= 4000000) {
        current = current + previous;
        previous = current - previous;
        if(current % 2 == 0)
            sum+=current;
    }
    cout << sum << endl;
    return 0;
}
