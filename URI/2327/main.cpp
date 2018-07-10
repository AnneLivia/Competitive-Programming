#include <iostream>

using namespace std;

int main()
{
    int n[10][10], sum = 0, aux = 0, t, flag = false;
    cin >> t;
    for ( int i = 0; i < t; i++) {
        for ( int j = 0; j < t; j++) {
            cin >> n[i][j];
        }
    }

    for ( int i = 0; i < t; i++) {
        for ( int j = 0; j < t; j++) {
            sum+=n[i][j];
        }

        if(i == 0)
            aux = sum;
        if(aux != sum) {
            flag = true;
            break;
        }

        sum = 0;
    }

    sum = 0;
    for ( int i = 0; i < t; i++) {
        for ( int j = 0; j < t; j++) {
            sum+=n[j][i];
        }

        if(aux != sum) {
            flag = true;
            break;
        }

        sum = 0;
    }
    sum = 0;
    for ( int i = 0; i < t; i++) {
        for ( int j = 0; j < t; j++) {
            if(i == j)
                sum+=n[i][j];
        }
    }
    if(aux != sum) {
        flag = true;
    }

    int i = t - 1;
    sum = 0;
    for ( int j = 0; j < t; j++) {
        sum+=n[i--][j];
    }

    if(aux != sum) {
        flag = true;
    }


    if(!flag)
        cout << aux << endl;
    else
        cout << -1 << endl;

    return 0;
}
