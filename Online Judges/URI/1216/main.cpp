#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    double dis, media = 0;
    string name;
    int cont = 0;

    while(true) {
        if(!getline(cin,name))
            break;
        if(!(cin >> dis))
            break;
        cont++;
        media +=dis;
        getchar();
    }

    printf("%.1f\n",media/cont);
    return 0;
}
