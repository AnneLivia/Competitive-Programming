#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

void change(string& co, const char& s) {
    if(s == 'G' || s == 'Q' || s == 'a' || s == 'k' || s == 'u')
        co+="0";
    else if (s == 'I' || s == 'S' || s == 'b' || s == 'l' || s == 'v')
        co+="1";
    else if (s == 'E' || s == 'O' || s == 'Y' || s == 'c' || s == 'm' || s == 'w')
        co+="2";
    else if (s == 'F' || s == 'P' || s == 'Z' || s == 'd' || s == 'n' || s == 'x')
        co+="3";
    else if (s == 'J' || s == 'T' || s == 'e' || s == 'o' || s == 'y')
        co+="4";
    else if (s == 'D' || s == 'N' || s == 'X' || s == 'f' || s == 'p' || s == 'z')
        co+="5";
    else if (s == 'A' || s == 'U' || s == 'K' || s == 'g' || s == 'q')
        co+="6";
    else if (s == 'C' || s == 'M' || s == 'W' || s == 'h' || s == 'r')
        co+="7";
    else if (s == 'B' || s == 'L' || s == 'V' || s == 'i' || s == 's')
        co+="8";
    else if (s == 'H' || s == 'R' || s == 'j' || s == 't')
        co+="9";
}

int main()
{
    int n, j;
    cin >> n;
    cin.ignore();
    string cop;
    char senha[10001];
    while(n--) {
        j = 0;
        cop = "";
        scanf(" %[^\n]",senha);
        for(int i = 0; i < strlen(senha) && i < 20 && j < 12; i++) {
            if(senha[i] != ' ') {
                change(cop,senha[i]);
                j++;
            }
        }

        cout << cop << endl;
    }
    return 0;
}
