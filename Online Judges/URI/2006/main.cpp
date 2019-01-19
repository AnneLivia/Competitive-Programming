#include <iostream>

using namespace std;

int main()
{
    int tCha, cha[5], contRight = 0;
    cin >> tCha;
    for ( int i = 0; i < 5; i++) {
        cin >> cha[i];
        if(cha[i] == tCha)
            contRight +=1;
    }
    cout << contRight << endl;
    return 0;
}
