#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Quick sort
int part (vector<int>&v, int low, int high) {
    int pivot = v[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (v[j] <= pivot) {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[high]);
    return (i + 1);
}

void quickSort(vector<int>&v, int low, int high) {
    if (low < high) {
        int pi = part(v, low, high);
        quickSort(v, low, pi - 1);
        quickSort(v, pi + 1, high);
    }
}

int main()
{
    int n, q, v, t = 1, pos;
    vector<int>ve;
    while(cin >> n >> q && n && q) {
        ve.assign(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> ve[i];
        }
        quickSort(ve, 0, n - 1);

        cout << "CASE# " << t++ << ":\n";
        while(q--) {
            cin >> v;
            pos = -1;
            for (int i = 0; i < n; i++) {
                if(v == ve[i]) {
                    pos = i;
                    break;
                }
            }
            if(pos == -1) {
                cout << v << " not found\n";
            } else {
                if(pos == 0 || ve[pos - 1] != v)
                    pos++;
                cout << v << " found at " << pos << endl;
            }
        }
    }
    return 0;
}
