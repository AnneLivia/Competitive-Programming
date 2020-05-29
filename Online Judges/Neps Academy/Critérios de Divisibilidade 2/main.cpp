#include <iostream>

using namespace std;

int main()
{
    string n;
    cin >> n;
    int number;
    if ((int)n.size() >= 2) {
        string lastTwo = "";
        lastTwo+=n[(int)n.size() - 2];
        lastTwo+=n[(int)n.size() - 1];

        number = stoi(lastTwo);
    } else {
        number = stoi(n);
    }

    // divisible by 4: ends in 00 or two last number are divisible by 4
    if (number == 0 || (number % 4 == 0)) {
        cout << "S\n";
    } else {
        cout << "N\n";
    }

    long long int sum = 0;
    for (int i = 0; i < (int)n.size(); i++) {
        sum+=(n[i] - '0');
    }

    // divisible by 5: ends in 0 or 5
    if (sum % 9 == 0) {
        cout << "S\n";
    } else {
        cout << "N\n";
    }
    // divisible by 25: ends in 0, 25, 50 or 75
    if (number == 0 || number == 25 || number == 50 || number == 75) {
        cout << "S\n";
    } else {
        cout << "N\n";
    }
    return 0;
}
