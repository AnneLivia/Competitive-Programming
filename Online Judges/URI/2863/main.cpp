#include <iostream>

using namespace std;

int main()
{
    int qtd;
    float vel, least;
    while(cin >> qtd) {
        least = 100;
        while(qtd--) {
            cin >> vel;
            if(vel < least)
                least = vel;
        }
        cout.precision(2);
        cout.setf(ios::fixed);
        cout << least << endl;
    }
    return 0;
}
