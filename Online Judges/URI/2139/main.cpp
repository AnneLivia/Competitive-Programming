#include <iostream>

using namespace std;

enum month {jan = 31, fev = 29, mar = 31, april = 30, may = 31, june = 30, july = 31, aug = 31, sep = 30, octb = 31, nov = 30, dez = 31};

int main()
{
    int mes, dia;
    while(cin >> mes >> dia) {
        if(dia == 25 && mes == 12)
            cout << "E natal!\n";
        else if (dia == 24 && mes == 12)
            cout << "E vespera de natal!\n";
        else if (dia > 25 && mes == 12) {
            cout << "Ja passou!\n";
        } else {
            switch(mes) {
            case 1:
                dia = 360 - dia;
                break;
            case 2:
                dia = 360 - (dia + jan);
                break;
            case 3:
                dia = 360 - (dia + fev + jan);
                break;
            case 4:
                dia = 360 - (dia + fev + jan + mar);
                break;
            case 5:
                dia = 360 - (dia + fev + jan + mar + april);
                break;
            case 6:
                dia = 360 - (dia + fev + jan + mar + april + may);
                break;
            case 7:
                dia = 360 - (dia + fev + jan + mar + april + may + june);
                break;
            case 8:
                dia = 360 - (dia + fev + jan + mar + april + may + june + july);
                break;
            case 9:
                dia = 360 - (dia + fev + jan + mar + april + may + june + july + aug);
                break;
            case 10:
                dia = 360 - (dia + fev + jan + mar + april + may + june + july + aug + sep);
                break;
            case 11:
                dia = 360 - (dia + fev + jan + mar + april + may + june + july + aug + sep + octb);
                break;
            case 12:
                dia = 360 - (dia + fev + jan + mar + april + may + june + july + aug + sep + octb + nov);
                break;
            }
            cout << "Faltam " << dia << " dias para o natal!\n";
        }

    }
    return 0;
}
