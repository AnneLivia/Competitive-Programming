#include <iostream>
using namespace std;

int main()
{
    int rodadas, ui, ri, li, ptUi, ptRi, ptLi;
    while(true) {
        cin >> rodadas;
        if(rodadas == 0)
            break;
        ptUi = ptRi = ptLi = 0;
        while(rodadas--) {
            cin >> ui >> ri >> li;
            if(ui % 2 == 0) {
                ptUi +=1;
                if(ui > ri && ui > li)
                    ptUi +=1;
            }
            if(ri % 2 == 0) {
                ptRi +=1;
                if(ri > ui && ri > li)
                    ptRi +=1;
            }
            if(li % 2 == 0) {
                ptLi +=1;
                if(li > ui && li > ri)
                    ptLi +=1;
            }
        }
        cout << ptUi << " " << ptRi <<  " " << ptLi << endl;
        if(ptLi > ptRi && ptLi > ptUi)
            cout << "Ingred\n";
        else if (ptRi > ptLi && ptRi > ptUi)
            cout << "Rita\n";
        else if (ptRi == ptLi && ptRi == ptUi)
            cout << "URI\n";
        else
            cout << "Uilton\n";
    }
    return 0;
}
