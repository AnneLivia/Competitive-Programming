//Codigo de exemplo
#include<iostream>
#define MAXN 10

using namespace std;

int main(){
    int mat[MAXN][MAXN], n, cont = 0, sum, magN;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }

    for(int i = 0; i < 1; i++)
    {
        sum = 0;
        for(int j = 0; j < n; j++)
        {
            sum += mat[i][j];
        }
        magN = sum;
    }

    for(int i = 0; i < n; i++)
    {
        sum = 0;
        for(int j = 0; j < n; j++)
        {
            sum += mat[i][j];
        }
        if(sum == magN)
            cont++;
    }

    for(int i = 0; i < n; i++)
    {
        sum = 0;
        for(int j = 0; j < n; j++)
        {
            sum += mat[j][i];
        }
        if(sum == magN)
            cont++;
    }
    sum = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j) {
                sum += mat[i][j];
            }
        }
    }

    if(sum == magN) {
        cont++;
    }

    int l = 0, c = n - 1;
    sum = 0;
    while(c >= 0)
    {
        sum += mat[l++][c--];
    }

    if(sum == magN)
        cont++;

    if(cont == (2 * n + 2))
        cout << magN << "\n";
    else
        cout << "-1\n";

    return 0;
}
