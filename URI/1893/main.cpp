#include <iostream>

using namespace std;

int main()
{
    int be, af;
    cin >> be >> af;
    if(af >= 0 && af <= 2)
        cout << "nova\n";
    else if (af >= 3 && af <= 96 && be >= af)
        cout << "minguante\n";
    else if (af >= 3 && af <= 96 && be <= af)
        cout << "crescente\n";
    else if (af >= 97 && af <= 100)
        cout << "cheia\n";

    return 0;
}
