#include <iostream>

using namespace std;

int main()
{
    string number = "";
    char t, l;
    bool stop = false;
    while (!stop) {
        number = "";
        cin >> t;
        // cin.peek is the 'peek' function on input streams
        // (in your case 'cin') retrieves the next character
        // from the stream without actually consuming it.
        // That means that you can "preview" the next character in the input
        while(cin.peek() != '\n') {
            cin >> l;
            if (t == '0' && l == '0') {
                stop = true;
                break;
            }
            if (l != t && !(number == "" && l == '0'))
                number+=l;
        }

        if (stop)
            break;

        if (number == "")
            number = "0";
        cout << number << endl;
    }
    return 0;
}
