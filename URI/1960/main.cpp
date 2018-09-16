#include <iostream>

using namespace std;

int main()
{
    string c[] = {"C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    string d[] = {"X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    string u[] = {"I","II","III","IV","V","VI","VII","VIII","IX"};

    int si, n;
    string x;
    cin >> x;


    n = stoi(x);
    x = to_string(n);

    si = (int)x.size();

    if(si == 1) {
        cout << u[(stoi(x) - 1)] << endl;
    } else if (si == 2) {
        if(x[0] != '0')
            cout << d[(x[0] - '0') - 1];
        if(x[1] != '0')
            cout << u[(x[1] - '0') - 1] << endl;
        else
            cout << endl;
    } else if (si == 3) {
        if(x[0] != '0')
            cout << c[(x[0] - '0') - 1];
        if(x[1] != '0')
            cout << d[(x[1] - '0') - 1];
        if(x[2] != '0')
            cout << u[(x[2] - '0') - 1] << endl;
        else
            cout << endl;
    }
    return 0;
}
