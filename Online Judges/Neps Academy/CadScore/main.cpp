#include <iostream>

using namespace std;


int main(){

    int po, n, v, total = 0;
    cin >> po >> n;
    while(n--) {
        cin >> v;
        po+=v;
        if(po < 0)
            po = 0;
        else if (po > 100)
            po = 100;
    }

    cout << po << endl;
}
