#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int main()
{
    long long unsigned int sum = 0, n, m, value, previous = -1, error = 0;

    cin >> n >> m;

    vector<long long unsigned int>v(n, 0);
    vector<long long unsigned int>aux(n, 0);

    for (long long unsigned int i = 0; i < n; i++) {
        cin >> v[i];
        aux[i] = v[i];
    }

    sum = v[0];
    for (int i = 1; i < n; i++) {
        int a1 = v[i - 1], a2 = m - v[i - 1];
        int b1 = v[i], b2 = m - v[i];
        int minimum = INT_MAX;

        if(a1 <= b1) {
            // cout << a1 << " -> Here a1\n";
            minimum = min(minimum, a1 + b1);
        }

        if(a1 <= b2) {
            // cout << a1 << " -> Here a2\n";
            minimum = min(minimum, a1 + b2);
        }

        if(a2 <= b1) {
            if((i - 2 >= 0 && v[i - 2] <= a2 && aux[i - 1] == v[i - 1]) || i  - 1 == 0) {
                // cout << a2 << " -> Here a3\n";
                minimum = min(minimum, a2 + b1);
            }
        }

        if(a2 <= b2) {
            if((i - 2 >= 0 && v[i - 2] <= a2 && aux[i - 1] == v[i - 1]) || i  - 1 == 0) {
                // cout << a2 << " -> Here a4\n";
                minimum = min(minimum, a2 + b2);
            }
        }

        bool ita2 = false;
        if(minimum == a1 + b1) {
            previous = b1;
        } else if (minimum == a1 + b2) {
            previous = b2;
        } else if (minimum == a2 + b1) {
            ita2 = true;
            previous = b1;
        } else if (minimum == a2 + b2) {
            ita2 = true;
            previous = b2;
        } else {
            error = true;
            break;
        }

        if(ita2) {
            v[i - 1] = a2;
            sum-=a1;
            sum+=a2;
        }

        v[i] = previous;
        sum+=previous;
    }

    if(error)
        cout << "-1" << endl;
    else
        cout << sum << endl;
    return 0;
}
