#include <iostream>

using namespace std;

int main()
{
    int t, sum;
    string n;
    cin >> t;
    while(t--){
        sum = 0;
        cin >> n;
        for (int i = 0; i < (int)n.size(); i++) {
            sum+=(int)(n[i] - '0');
        }
        cout << sum << endl;
    }
    return 0;
}
