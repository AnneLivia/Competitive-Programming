#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int qA, qB, n, contR;
    vector<int>b,r;
    while(true) {
        b.clear();
        r.clear();
        cin >> qA >> qB;
        contR = 0;
        if(qA == 0 && qB == 0)
            break;
        while(qB--) {
            cin >> n;
            if(find(b.begin(),b.end(),n) != b.end()) {
                if(find(r.begin(),r.end(),n) == r.end()) {
                    contR++;
                    r.push_back(n);
                }
            } else {
                b.push_back(n);
            }
        }
        cout << contR << endl;
    }
    return 0;
}
