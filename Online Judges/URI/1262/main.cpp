#include <iostream>

using namespace std;

int main()
{
    int procs, cycle, i, cont;
    string read;

    while(cin >> read >> procs) {
        cycle = cont = i = 0;
        read+=" ";
        while(i < (int)read.length()){
            if(read[i] == 'R' && cont < procs) {
                cont++;
            } else {
                if(read[i] == 'W')
                    cycle++;
                if(cont != 0)
                    cycle++;
                if(read[i] == 'R')
                    i--;
                cont = 0;
            }
            i++;
        }
        cout << cycle << endl;
    }
    return 0;
}
