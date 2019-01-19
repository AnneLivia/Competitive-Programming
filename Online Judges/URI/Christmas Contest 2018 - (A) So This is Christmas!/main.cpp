#include <iostream>

using namespace std;

int main()
{
    int j;
    cin >> j;

    string natal = "Ent";
    for(int i = 0; i < j; i++)
        natal+="a";
    natal+="o eh N";
    for(int i = 0; i < j; i++)
        natal+="a";
    natal+="t";
    for(int i = 0; i < j; i++)
        natal+="a";
    natal+="l!";
    cout << natal << endl;
    return 0;
}
