#include <iostream>


using namespace std;

int main()
{
    string number;

    while(true) {
        string formedNumber = "";
        if(!getline(cin,number)) {
            break;
        }
        for(int i = 0; i < number.size();i++) {
            if(number[i] >= 48 && number[i] <= 57 || number[i] == 42 || number[i] == 35) {
                formedNumber +=number[i];
            } else if (toupper(number[i] >= 65) || toupper(number[i]) <= 90) {
                switch(toupper(number[i])) {
                case 'A' :
                case 'B' :
                case 'C' : formedNumber+='2';
                           break;
                case 'D' :
                case 'E' :
                case 'F' : formedNumber+='3';
                           break;
                case 'G' :
                case 'H' :
                case 'I' : formedNumber+='4';
                           break;
                case 'J' :
                case 'K' :
                case 'L' : formedNumber+='5';
                           break;
                case 'M' :
                case 'N' :
                case 'O' : formedNumber+='6';
                           break;
                case 'P' :
                case 'Q' :
                case 'R' :
                case 'S' : formedNumber+='7';
                           break;
                case 'T' :
                case 'U' :
                case 'V' : formedNumber+='8';
                           break;
                case 'W' :
                case 'X' :
                case 'Y' :
                case 'Z' : formedNumber+='9';
                           break;
                }
            }
        }
        cout << formedNumber << endl;
    }
    return 0;
}
