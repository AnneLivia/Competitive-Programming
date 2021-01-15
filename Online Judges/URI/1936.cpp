#include <iostream>
#include <map>

using namespace std;

map<int, int> ma {
    {1,1},
    {2,2},
    {3,6},
    {4,24},
    {5,120},
    {6,720},
    {7,5040},
    {8,40320}
};

int main() {
    int a, i = 8, cont = 0;
    cin >> a;
    int  sum = a;
    while(sum) {
        if (ma.at(i) > sum) {
            i--;
        } else if (ma.at(i) == a) {
            cont++; break;
        } else {
            sum-=ma.at(i);
            cont++;
        }
    }

    cout << cont << endl;
    return 0;
}

