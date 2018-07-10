#include <iostream>
#include "stdio.h"
using namespace std;


int main()
{
    int n, num;
    string answer = "";
    do {
        cin >> n;
    }while(n > 10000);

    for(int i = 1; i <= n; i++) {
       cin >> num;
       if(num == 0) {

            answer += "NULL\n";
            continue;
        }
       if(num % 2 == 0)
             answer += "EVEN ";
       else
            answer += "ODD ";
       if(num > 0)
             answer += "POSITIVE\n";
        else
             answer += "NEGATIVE\n";
    }

    cout <<  answer;
    return 0;
}
