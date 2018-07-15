#include <iostream>

using namespace std;

int main()
{
    string dayword;
    char c;
    int dia1, hora1, minuto1, segundo1;
    int dia2, hora2, minuto2, segundo2;
    int rdia, rhora, rminuto, rsegundo;

    cin >> dayword >> dia1;
    cin >> hora1 >> c >> minuto1 >> c >> segundo1;
    cin >> dayword >> dia2;
    cin >> hora2 >> c >> minuto2 >> c >> segundo2;

    rdia = dia2 - dia1;
    rhora = hora2 - hora1;
    rminuto = minuto2 - minuto1;
    rsegundo = segundo2 - segundo1;

    if(rhora < 0) {
        rhora+=24;
        rdia--;
    }

    if(rminuto < 0) {
        rminuto+=60;
        rhora--;
    }

    if(rsegundo < 0) {
        rsegundo += 60;
        rminuto--;
    }

    cout << rdia << " dia(s)\n";
    cout << rhora << " hora(s)\n";
    cout << rminuto << " minuto(s)\n";
    cout << rsegundo << " segundo(s)\n";
    return 0;
}
