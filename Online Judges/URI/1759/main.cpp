#include <iostream>

using namespace std;

int main()
{
    int qHo;
    cin >> qHo;
    for ( int i = 0; i < qHo; i++) {
        cout << "Ho";
        if(i < qHo - 1)
            cout << " ";
        else
            cout << "!\n";
    }

    return 0;
}
