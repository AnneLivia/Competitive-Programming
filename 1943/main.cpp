#include <iostream>

using namespace std;

int main()
{
    int collocation;
    cin >> collocation;
    if(collocation == 1) {
        cout << "Top 1\n";
    } else if (collocation > 1 && collocation <= 3) {
        cout << "Top 3\n";
    } else if (collocation > 3 && collocation <= 5) {
        cout << "Top 5\n";
    } else if (collocation > 5 && collocation <= 10) {
        cout << "Top 10\n";
    } else if (collocation > 10 && collocation <= 25) {
        cout << "Top 25\n";
    } else if (collocation > 25 && collocation <= 50) {
        cout << "Top 50\n";
    } else if (collocation > 50 && collocation <= 100) {
        cout << "Top 100\n";
    }
    return 0;
}
