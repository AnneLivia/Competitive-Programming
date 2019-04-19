#include <iostream>

using namespace std;

int main()
{
    int ports, commands, movement, station, status = 0, number = 0;

    cin >> ports >> commands >> station;

    station--;

    while(commands--) {
      //  cout << status << " " << number << endl;
        cin >> movement;
        if(status == station) {
            number++;
        }
        if(movement == 1) {
            status = (status + 1) % ports;
        } else {
            status-=1;
            if(status == -1)
                status = ports - 1;
        }

    }
    if(status == station)
        number++;
    cout << number << endl;

    return 0;
}
