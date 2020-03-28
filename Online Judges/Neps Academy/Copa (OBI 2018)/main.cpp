#include <iostream>

using namespace std;

int main()
{
    int masterlu, masterkung;

    cin >> masterkung >> masterlu;

    if ((masterlu <= 8 && masterkung > 8) ||
        (masterkung <= 8 && masterlu > 8)) {
        cout << "final\n";
    } else {
        if (((masterlu <= 4 && masterkung > 4) || (masterkung <= 4 && masterlu > 4)) ||
            ((masterlu <= 12 && masterkung > 12) || (masterkung <= 12 && masterlu > 12))) {
            cout << "semifinal\n";
        } else {
            if (((masterlu <= 2 && masterkung > 2) || (masterkung <= 2 && masterlu > 2)) ||
            ((masterlu <= 6 && masterkung > 6) || (masterkung <= 6 && masterlu > 6)) ||
            ((masterlu <= 10 && masterkung > 10) || (masterkung <= 10 && masterlu > 10))||
            ((masterlu <= 14 && masterkung > 14) || (masterkung <= 14 && masterlu > 14))) {
                cout << "quartas\n";
            } else {
                cout << "oitavas\n";
            }
        }
    }
    return 0;
}
