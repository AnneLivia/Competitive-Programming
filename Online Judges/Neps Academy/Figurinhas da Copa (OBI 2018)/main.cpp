#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, c, co, to = 0;

    cin >> n >> c >> co;

    int ca[c], com[co];

    for (int i = 0; i < c; i++) {
        cin >> ca[i];
    }

    for (int i = 0; i < co; i++) {
        cin >> com[i];
    }

    for (int i = 0; i < c; i++) {
       bool found = 0;
       for (int j = 0; j < co; j++) {
            if (ca[i] == com[j]) {
                found = 1;
                break;
            }
       }
       if (!found)
            to++;
    }
    cout << to << endl;
    return 0;
}
