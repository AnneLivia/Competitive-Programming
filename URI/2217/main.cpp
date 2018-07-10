#include <iostream>
using namespace std;

int main()
{
    long long unsigned int number, gettingResult;
    string result;
    int test;
    cin >> test;
    while(test--) {
        cin >> number;
        if(number % 2 == 0)
            cout << "1\n";
        else
            cout << "9\n";
    }
    return 0;
}
