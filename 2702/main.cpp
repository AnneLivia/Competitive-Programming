#include <iostream>

using namespace std;

int main()
{
    int qtf,qtb,qtm,qtpf,qtpb,qtpm, dif = 0;
    cin >> qtf >> qtb >> qtm;
    cin >> qtpf >> qtpb >> qtpm;
    if(qtf >= qtpf)
        dif +=0;
    else
        dif += (qtpf - qtf);
    if(qtb >= qtpb)
        dif += 0;
    else
        dif += (qtpb - qtb);
    if(qtm >= qtpm)
        dif += 0;
    else
        dif += (qtpm - qtm);

    cout << dif << endl;
    return 0;
}
