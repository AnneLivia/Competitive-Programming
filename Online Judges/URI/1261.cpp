#include <iostream>
#include <map>

using namespace std;

int main() {

    int m, n, price;
    string cargo, description;
    cin >> m >> n;
    map<string, int> haypoint;

    while(m--) {
        cin >> cargo;
        cin >> haypoint[cargo];
    }

    // reading the description of the job
    while(n--) {
        price = 0;
        description = "";
        while(description != ".") {
            cin >> description; // reading word by word
            if(haypoint.find(description) != haypoint.end()) {
                // existe, só somar
                price+=haypoint[description];
            }
        }

        cout << price << endl;
    }
    return 0;
}
