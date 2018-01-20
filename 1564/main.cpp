#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    string complain;
    while(getline(cin,complain)) {
        if(complain.compare("0")  == 0)
            cout << "vai ter copa!\n";
        else if(complain.compare("") == 0)
            break;
        else
            cout << "vai ter duas!\n";
    }
    return 0;
}
