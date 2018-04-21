#include <iostream>

using namespace std;

int main()
{
    int let, ovo, trig, cont = 0;
    cin >> trig >> ovo >> let;
    //2 trigo, 3 ovos, 5 leite

    let/=5;
    ovo/=3;
    trig/=2;

    if (let <= ovo && let <= trig)
        cout << let << endl;
    else if (ovo <= let && ovo <= trig) {
        cout << ovo << endl;
    } else if (trig <= ovo && trig <= let)
        cout << trig << endl;

    return 0;
}
