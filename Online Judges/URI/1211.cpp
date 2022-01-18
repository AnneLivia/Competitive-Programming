#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    problem: XVI Maratona de Programação IME-USP, 2012.
    URL: https://www.beecrowd.com.br/judge/pt/problems/view/1211
*/

int main() {
    int n, cont = 0, equals = 0;;


    vector<string>phone;

    while(cin >> n) {
        cont = 0;
        phone.assign(n, "");
        for(int i = 0; i < n; i++)
            cin >> phone[i];

        sort(phone.begin(), phone.end());

        for (int i = 1; i < n; i++) { // run starting from 2 phone
            equals = 0;
            for (int j = 0; j < (int)phone[i].size(); j++) { // verifying all chars from phone and comparing with the previous one
                /*
                    535456
                    535488 <-
                    835456

                */
                if (phone[i][j] == phone[i-1][j]) {
                    equals++;
                } else {
                    break; // finished the prefix with equal numbers
                }
            }
            cont+=equals; // 4
        }

        cout << cont << endl;
    }
    return 0;
}
