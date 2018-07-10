#include <iostream>

using namespace std;

int main()
{
    long long int n, bigger;
    bool firstNumber = true, working = true;
    while(cin >> n) {
        if(firstNumber) {
            bigger = n;
            firstNumber = false;
        } else if(n > maior && working)
            bigger = n;
        else
            working = false;
    }
    if(!ok) {
        cout << bigger+1 << endl;
    } else {
        cout << bigger+1 << endl;
    }
    return 0;
}
