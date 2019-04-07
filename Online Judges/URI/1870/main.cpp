#include <iostream>
#include <vector>

using namespace std;

struct Fan {
    int value, x, y;
};

int main()
{
    int n, c, p, balloon, diff;
    vector<vector<int> > v;

    while(cin >> n >> c >> p && n && c && p) {
        v.assign(n, vector<int>(c, 0));
        balloon = 1; // Balloon it's full
        for (int i = 0; i < n; i++) {
            for(int j = 0; j < c; j++) {
                cin >> v[i][j];
            }
        }

        Fan fanLeft = {0,0,0}, fanRight = {0,0,0};
        int i;
        for(i = 0; i < n; i++) {

            if(v[i][p - 1] != 0) { // there's a fan
                balloon = 0; // pop
                break;
            }

            for(int l = p - 1; l >= 0; l--) {
                if(v[i][l] != 0) {
                    fanLeft.value = v[i][l];
                    fanLeft.x = i;
                    fanRight.y = l;
                    break;
                }
            }

            for(int r = p - 1; r < c; r++) {
                if(v[i][r] != 0) {
                    fanRight.value = v[i][r];
                    fanRight.x = i;
                    fanRight.y = r;
                    break;
                }
            }

            diff = abs(fanLeft.value - fanRight.value);
            if(fanLeft.value > fanRight.value) {
                // to the right
                p+=diff;
                if(p >= fanRight.y + 1) {
                    balloon = 0; // pop
                    break;
                }
            } else if (fanLeft.value < fanRight.value) {
                // to the left
                p-=diff;
                if(p <= fanLeft.y + 1) {
                    balloon = 0; // pop
                    break;
                }
            }
        }
        if(!balloon) {
            if(p <= 0)
                p = 1;
            else if  (p > c)
                p = c;
            cout << "BOOM " << i + 1 << " " << p << endl;
        } else {
            cout << "OUT " << p << endl;
        }
    }
    return 0;
}
