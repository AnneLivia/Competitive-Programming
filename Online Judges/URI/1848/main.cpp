#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int cont = 0, number = 0;
    string gritoOuPiscada, grito = "caw caw";
    while(cont < 3) {
        getline(cin, gritoOuPiscada);
        if(gritoOuPiscada.compare(grito) == 0) {
            cout << number << endl;
            cont++;
            number = 0;
        } else {
            if(gritoOuPiscada.compare("--*") == 0) {
                number +=1;
            } else if (gritoOuPiscada.compare("*--") == 0) {
                number +=4;
            } else if (gritoOuPiscada.compare("-**") == 0) {
                number +=3;
            } else if (gritoOuPiscada.compare("-*-") == 0) {
                number +=2;
            } else if (gritoOuPiscada.compare("***") == 0) {
                number +=7;
            } else if (gritoOuPiscada.compare("*--") == 0) {
                number +=4;
            } else if (gritoOuPiscada.compare("*-*") == 0) {
                number +=5;
            } else if (gritoOuPiscada.compare("**-") == 0) {
                number +=6;
            }
        }
    }
    return 0;
}
