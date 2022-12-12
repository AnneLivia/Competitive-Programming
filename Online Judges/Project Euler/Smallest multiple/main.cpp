#include <iostream>

using namespace std;

int main()
{
    int number = 20, found = 0, no;

    while(!found) {
        no = 0;
        for (int i = 1; i <= 20 && !no; i++) {
            if(number % i != 0)
                no = 1;
        }

        if(!no)
            found = 1;
        else
            number++;
    }

    cout << number << endl;
    return 0;
}
