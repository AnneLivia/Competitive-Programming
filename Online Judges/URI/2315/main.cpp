#include <iostream>
#include <map>

using namespace std;

int days(int day1, int day2, int month1, int month2) {

    int vet[12] = {31,28,31,30, 31,30,31,31,30,31,30,31};
    int d = (vet[month1 - 1] - day1);

    for(int i = month1; i < month2; i++) {
        d+=vet[i];
    }


    d = d - (vet[month2 - 1] - day2);
    return d;
}

int main()
{
    int day1, month1, day2, month2;



    cin >> day1 >> month1 >> day2 >> month2;

    if(month1 == month2) {
        cout << day2 - day1 << endl;
    } else {
        int totalDay = days(day1,day2, month1, month2);

        cout << totalDay << endl;
    }

    return 0;
}
