#include <iostream>

using namespace std;
void computePoints(const int& gol1, const int& gol2, int& time1, int& time2) {
    if(gol1 > gol2)
            time1 += 3;
        else if (gol1 < gol2)
            time2 += 3;
        else {
            time1 += 1;
            time2 +=1;
    }
}

int main()
{
    int time1, time2, cTestes, gol1, gol2, n1,n2, golVis1, golVis2;
    char c;
    cin >> cTestes;
    while(cTestes--) {
        time1 = time2 = gol1 = gol2 = 0;
        cin >> n1 >> c >> n2;
        gol1 +=n1;
        gol2 +=n2;
        golVis2 = gol2;
        computePoints(n1,n2,time1,time2);
        cin >> n1 >> c >> n2;
        gol1 +=n2;
        gol2 +=n1;
        golVis1 = n2;
        computePoints(n1,n2,time2,time1);
        if(time1 > time2)
            cout << "Time 1\n";
        else if (time2 > time1)
            cout << "Time 2\n";
        else {
            if(gol1 > gol2)
                cout << "Time 1\n";
            else if (gol1 < gol2)
                cout << "Time 2\n";
            else {
                if(golVis1 > golVis2)
                    cout << "Time 1\n";
                else if (golVis1 < golVis2)
                    cout << "Time 2\n";
                else
                    cout << "Penaltis\n";
            }
        }

    }
    return 0;
}
