#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // programs installed on the company's computer and available on the web (respectively)
    int n, m;

    cin >> n >> m;

    vector<pair<long long int, long long int> >company(n, pair<long long int,long long int>());
    vector<pair<long long int, long long int> >internet;

    // program id  (number) and version
    int pc, vc;
    for (int i = 0; i < n; i++) {
        cin >> pc >> vc;
        company[i] = make_pair(pc,vc);
    }

    for (int i = 0; i < m; i++) {
        cin >> pc >> vc;
        auto it = find_if(internet.begin(), internet.end(), [pc](const pair<long long int, long long int>& cp) {
            return (cp.first == pc);
        });

        if(it != internet.end()) {
            if(it->second < vc) {
                it->second = vc;
            }
        } else {
            internet.push_back(make_pair(pc,vc));
        }
    }

    sort(internet.begin(), internet.end(), [](const pair<long long int, long long int>& c1, const pair<long long int, long long int>& c2) {
        return c1.first < c2.first;
    });

    // for each program and version available on web, must check if the version is greater than the installed
    for_each(internet.begin(), internet.end(), [company](const pair<long long int, long long int>& pro){
        auto it = find_if(company.begin(), company.end(), [pro](const pair<long long int, long long int>& cp) {
            return (cp.first == pro.first);
        });

        // found
        if((it != company.end() && it->second < pro.second) ||(it == company.end())) {
            cout << pro.first << " " << pro.second << endl;
        }
    });

    return 0;
}
