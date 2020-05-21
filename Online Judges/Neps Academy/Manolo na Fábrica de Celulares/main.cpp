#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int comp[6] = {0}, mod[3] = {0};
    int n, t, cana, canb, canc;
    cana = canb = canc = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        comp[t]++;

        if (comp[1] && comp[3] && comp[5]) {
            comp[1]--;
            comp[3]--;
            comp[5]--;
            mod[0]++;
        }

        if (comp[1] && comp[4]) {
            comp[1]--;
            comp[4]--;
            mod[1]++;
        }

        if (comp[2] && comp[4]) {
            comp[2]--;
            comp[4]--;
            mod[2]++;
        }
    }

    cout << "A: " << mod[0] << endl;
    cout << "B: " << mod[1] << endl;
    cout << "C: " << mod[2] << endl;

    return 0;
}
