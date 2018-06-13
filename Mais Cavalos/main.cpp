#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<char,int>m {
        {'a',1}, {'b',2}, {'c',3},
        {'d',4}, {'e',5}, {'f',6},
        {'g',7}, {'h',8},
    };
    char l1, l2; int n1, n2, nuLe1, nuLe2;
    cin >> l1 >> n1 >> l2 >> n2;
    nuLe1 = m[l1];
    nuLe2 = m[l2];

    if(n1 - 2 == n2 && nuLe1 - 1 == nuLe2 ||
       n1 - 2 == n2 && nuLe1 + 1 == nuLe2 ||
       n1 - 1 == n2 && nuLe1 + 2 == nuLe2 ||
       n1 + 1 == n2 && nuLe1 + 2 == nuLe2 ||
       n1 + 2 == n2 && nuLe1 + 1 == nuLe2 ||
       n1 + 2 == n2 && nuLe1 - 1 == nuLe2 ||
       n1 - 1 == n2 && nuLe1 - 2 == nuLe2 ||
       n1 + 1 == n2 && nuLe1 - 2 == nuLe2 )
        cout << "VALIDO\n";
    else
        cout << "INVALIDO\n";
    return 0;
}
