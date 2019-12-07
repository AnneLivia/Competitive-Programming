#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int n, din = 0, i = 5;
    cin >> n;

    vector<int>v = {1,5,10,25,50,100};

    while(n > 0) {
        if(v[i] > n) {
            i--;
        } else {
            n-=v[i];
            din++;
        }
    }

    cout << din << endl;
    return 0;
}
