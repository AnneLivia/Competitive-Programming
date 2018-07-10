#include <iostream>
#include <string>

using namespace std;

int main()
{
    string nForm;
    getline(cin,nForm);
    if(nForm.size() <= 80)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
