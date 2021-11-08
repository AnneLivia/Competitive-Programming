#include <iostream>
#include <vector>

using namespace std;

int main() {

    int t_area, n_stars, cont = 0;

    cin >> t_area >> n_stars;

    vector<int>f(n_stars, 0);

    for(int i = 0; i < n_stars; i++) {
        cin >> f[i];
    }

    for (int i = 0; i < n_stars; i++) {
        if (f[i] * t_area >= 40000000) {
            cont++;
        }
    }


    cout << cont << endl;
    return 0;
}
