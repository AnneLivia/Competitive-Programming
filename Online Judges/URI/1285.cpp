#include <iostream>

using namespace std;

bool check_digits(string str) {
    for (int  i = 0; i < (int)str.size(); i++) {
        for (int j = 0; j < (int)str.size(); j++) {
            if (str[i] == str[j] && i != j)
                return true;
        }
    }
    return false;
}


int main() {
    int n, m, cont = 0;

    while(cin >> n >> m) {
        cont = 0;
        for (int i = n; i <= m; i++) {
            if (!check_digits(to_string(i)))
                cont++;
        }

        cout << cont << endl;
    }


    return 0;
}
