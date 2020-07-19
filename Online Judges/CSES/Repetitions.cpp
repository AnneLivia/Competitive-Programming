#include <iostream>
#include <cstring>

using namespace std;


int main() {
    char c, last = '1';

    // count is 1, because it's guarantee that at least one char is goint to be inserted
    int total = -1, count = 1;

    while(cin.peek() != '\n') {
        cin >> c;
    
        if (c == last)
            count++;
        else {
            if (last != '1')
                count = 1;
        }
        
        if (count > total)
            total = count;

        last = c;
    }
    
    cout << total << endl;
    return 0;
}