#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n, maior;
    string t, ans;
    map<char,int>m;
    cin >> n;
    cin.ignore();
    while(n--) {
        m.clear();
        ans = "";
        maior = 0;
        getline(cin,t);
        for ( int i = 0; i < (int)t.size(); i++) {
            if(m.find(tolower(t[i])) != m.end()) {
                m.at(tolower(t[i]))++;
            } else {
                if(tolower(t[i]) >= 'a' && tolower(t[i]) <= 'z') {
                    m.insert(make_pair(tolower(t[i]),1));
                }
            }
        }

        for ( auto i : m) {
            if(i.second > maior)
                maior = i.second;
        }

        for(auto i : m) {
            if(i.second == maior)
                ans+=i.first;
        }

        cout << ans << endl;
    }
    return 0;
}
