#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t, contj = 0, jumps = 0;
    vector<string>s;
    string aux;

    cin >> t;
    while(t--) {
        cin >> aux;
        s.push_back(aux);
    }

    s.push_back(" ");
    for(int i = 0; i < (int)s.size(); i++) {
        if(s[i][0] == '.') {
            contj++;
        } else {
            if(contj > 0 && contj <= 2) {
                jumps++;
                contj = 0;
            } else if (contj > 3) {
                break;
            }
        }
    }

    if(contj > 2)
        cout << "N\n";
    else
        cout << jumps << endl;
    return 0;
}
