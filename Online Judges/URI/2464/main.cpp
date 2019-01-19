#include <iostream>
#include <map>

using namespace std;

int main()
{
    string l1, l2, r = "";
    char a = 'a';
    map<char,int>m;
    for(int i = 1; i <= 26; i++) {
        m.insert(make_pair(a++,i));
    }

    cin >> l1;
    cin >> l2;

    for(int i = 0; i < (int) l2.size(); i++) {
        r+=l1[m.at(l2[i]) - 1];
    }

    cout << r << endl;
    return 0;
}
