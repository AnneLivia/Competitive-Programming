#include <iostream>

using namespace std;

int main()
{
    int card[2];
    cin >> card[0] >> card[1];
    if(card[0] == card[1]) {
        cout << card[0] << endl;
    } else if(card[0] > card[1]) {
        cout << card[0] << endl;
    } else {
        cout << card[1] << endl;
    }
    return 0;
}
