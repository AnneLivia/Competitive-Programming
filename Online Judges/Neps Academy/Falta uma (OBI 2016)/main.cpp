#include <iostream>
#include <vector>

using namespace std;

int fat(int n) {
    if (n <= 1)
        return 1;
    return n * fat(n - 1);
}

int main()
{
    int n, fatn, t;
    cin >> n;

    int contfatn = fatn = fat(n) - 1;

    vector<vector<int> > cont(n, vector<int>(n, 0));
    while(contfatn--) {
        for (int i = 0; i < n; i++) {
            cin >> t;
            cont[i][t - 1]++;
        }
    }

    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (cont[i][j] < ((fatn + 1)/ n)) {
                if (i != 0)
                    cout << " ";
                cout << j + 1;
                break;
            }
        }
    }
    cout << endl;
    return 0;
}
