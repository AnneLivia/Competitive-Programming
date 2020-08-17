#include <iostream>

using namespace std;

int main()
{
    int d1, h1, m1, d2, h2, m2, shour, smin;

    cin >> d1 >> h1 >> m1;
    cin >> d2 >> h2 >> m2;
    /*
        Steps:
        - first calculate the hour duration from day 1 to day2 which is 24
          since a day has 24 hours, times (d2 - d1), which is the number of
          days that has passed, then subtract by h1, plus hour 2.
            formula 1: (24 * abs(day1 - day2) - h1) + h2; -> this gives the number of hours passed
        - then calculate the minute duration, which is similar to calculate the hour duration
            formula 2: (60 * formula1 - m1) + m2
        - then multiply my 60 and it gives the duration in seconds.


    */
    shour = ((24 * (d2 - d1)) - h1) + h2;

    smin = ((60 * shour) - m1) + m2;

    cout << smin * 60 << endl;

    return 0;
}
