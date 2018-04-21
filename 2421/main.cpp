#include <iostream>

using namespace std;

struct album {
    int lar, alt;
};


int main()
{
    album al, ph1, ph2;

    cin >> al.lar >> al.alt;
    cin >> ph1.lar >> ph1.alt;
    cin >> ph2.lar >> ph2.alt;

    if(ph1.lar + ph2.lar <= al.lar && ph1.alt <= al.alt && ph2.alt <= al.alt) {
        cout << "S\n";
    } else if (ph1.alt + ph2.alt <= al.alt && ph1.lar <= al.lar && ph2.lar <= al.lar) {
        cout << "S\n";
    } else if (ph1.alt + ph2.lar <= al.alt && ph2.alt <= al.lar && ph1.lar <= al.lar) {
        cout << "S\n";
    } else if (ph1.lar + ph2.alt <= al.alt && ph1.alt <= al.lar && ph2.lar <= al.lar) {
        cout << "S\n";
    } else if(ph1.lar + ph2.lar <= al.alt && ph1.alt <= al.lar && ph2.alt <= al.lar) {
        cout << "S\n";
    } else if (ph1.alt + ph2.alt <= al.lar && ph1.lar <= al.alt && ph2.lar <= al.alt) {
        cout << "S\n";
    } else if (ph1.alt + ph2.lar <= al.lar && ph2.alt <= al.alt && ph1.lar <= al.alt) {
        cout << "S\n";
    } else if (ph1.lar + ph2.alt <= al.lar && ph1.alt <= al.alt && ph2.lar <= al.alt) {
        cout << "S\n";
    } else {
        cout << "N\n";
    }


    return 0;
}
