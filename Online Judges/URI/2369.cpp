
#include <iostream>

using namespace std;

int main() {

    int n, sum = 7;
    cin >> n;

    if (n > 10) {
        int i = 11;
        while(i <= n) {
            if (i >= 10 && i <= 30)
                sum+=1;
            else if (i >= 31 && i <= 100)
                sum+=2;
            else if (i >= 101)
                sum+=5;
            i++;
        }

    }


    cout << sum << endl;
    return 0;
}
