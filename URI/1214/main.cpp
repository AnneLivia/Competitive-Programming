#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int c, qtStudents, cont;
    float sAndM;
    int *n;
    cin >> c;

    for ( int i = 0; i < c; i++) {
        cont = 0, sAndM = 0;
        cin >> qtStudents;
        n = new int[qtStudents];
        for ( int j = 0; j < qtStudents; j++) {
            cin >> n[j];
            sAndM+=n[j];
        }
        sAndM = sAndM / qtStudents;
        for ( int j = 0; j < qtStudents; j++) {
            if(n[j] > sAndM)
                cont++;
        }

        printf("%.3f%%\n",(float)cont/qtStudents * 100);
        delete[] n;
    }

    return 0;
}
