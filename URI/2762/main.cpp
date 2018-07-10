#include <iostream>

using namespace std;

int main()
{
    string n, aux1,aux2;
    bool ja;
    while(cin >> n) {
        aux1 = "";
        aux2 = "";
        ja = false;
        int posp;
        for (int i = 0; i < (int)n.size(); i++) {
            if(ja) {
                aux1+=n[i];
            }
            if(n[i] == '.') {
                ja = true;
                posp = i;
            }
        }

        for ( int i = 0; i < posp; i++) {
            aux2+=n[i];
        }
        cout << stoi(aux1) << "." << aux2 << endl;
    }
    return 0;
}
