#include <iostream>
#include <string>

using namespace std;

int main()
{
    int qtdLed, t;
    string number;
    cin >> t;

    while(t--) {
        cin >> number;
        qtdLed = 0;
        for ( int i = 0; i < number.length(); i++) {
            switch(number[i]) {
                case '0' : qtdLed +=6;
                           break;
                case '1' : qtdLed +=2;
                           break;
                case '2' : qtdLed +=5;
                           break;
                case '3' : qtdLed +=5;
                           break;
                case '4' : qtdLed +=4;
                           break;
                case '5' : qtdLed +=5;
                           break;
                case '6' : qtdLed +=6;
                           break;
                case '7' : qtdLed +=3;
                           break;
                case '8' : qtdLed +=7;
                           break;
                case '9' : qtdLed +=6;
                           break;
            }
        }
        cout <<  qtdLed << " leds\n";
    }
    return 0;
}
