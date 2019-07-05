#include <iostream>
#include <vector>

using namespace std;

int bin(const int& n, const vector<int>& v) {
    int ini = 0, en = (int)v.size() - 1;

    while(ini <= en) {
        int mid = (ini + en) >> 1;
        if(v[mid] == n)
            return mid;
        else if (v[mid] < n) {
            ini = mid + 1;
        } else {
            en = mid - 1;
        }
    }

    return -1;
}

int main()
{

    int elements, query;

    cin >> elements >> query;

    vector<int>n(elements, 0);

    for (int i = 0; i < elements; i++) {
        cin >> n[i];
    }

    while(query--) {
        cin >> elements;
        cout << bin(elements, n) << endl;
    }
    return 0;
}
