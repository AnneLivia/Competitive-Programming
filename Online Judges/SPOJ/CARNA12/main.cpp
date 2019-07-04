#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<float>v(5, 0);

    for (int i = 0; i < 5; i++) {
        cin >> v[i];
    }

    // insertion sort
    for (int i = 1; i < 5; i++) {
        for(int j = 0; j < i; j++) {
            if(v[i] < v[j]) {
                swap(v[i],v[j]);
            }
        }
    }

    float sum = 0;
    for(int i = 1; i < 4; i++)
        sum+=v[i];

    cout.precision(1);
    cout.setf(ios::fixed);
    cout << sum << endl;
    return 0;
}
