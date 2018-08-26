#include <iostream>
#include <cmath>

using namespace std;

void h2d(string& num, string& r) {
    string aux = "";
    long long int n, res = 0, up = 0;
    for(int i = (int)num.size() - 1; i >= 0; i--) {
        if(toupper(num[i]) == 'A')
            n = 10;
        else if (toupper(num[i]) == 'B')
            n = 11;
        else if (toupper(num[i]) == 'C')
            n = 12;
        else if (toupper(num[i]) == 'D')
            n = 13;
        else if (toupper(num[i]) == 'E')
            n = 14;
        else if (toupper(num[i]) == 'F')
            n = 15;
        else
            n = num[i] - '0';
        res+=(n * pow(16,up++));
    }
    r = to_string(res);
}
int main()
{
    string n;
    while(cin >> n) {
        string aux = "";
        if((int)n.size() >= 2 && n[1] == 'x') {
            for(int i = 2; i < (int)n.size(); i++)
                aux+=n[i];
        } else {
            aux = n;
        }

        if(n[1] != 'x' && stoll(aux) < 0)
            break;

        if(n[1] == 'x' || n[1] == 'X') {
            h2d(aux,n);
            if(stoll(n) < 0)
                break;
            cout << dec << n << endl;
        } else {
            cout << hex << "0x" << uppercase << stoll(aux) << endl;
        }
    }
    return 0;
}
