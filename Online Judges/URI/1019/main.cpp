#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    int segundo, hora, minuto;
    cin >> segundo;
    hora = segundo / 3600;
    segundo = segundo - (hora * 3600);
    minuto =  segundo / 60;
    segundo = (segundo - (minuto * 60));
    cout << hora << ":" << minuto << ":" << segundo << endl;
	return 0;
}
