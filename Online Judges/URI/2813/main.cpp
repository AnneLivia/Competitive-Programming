#include <iostream>

using namespace std;

int main()
{
    int n, uH, uW, auxUH, auxUW;
    string weather1, weather2;

    uH = uW = auxUH = auxUW = 0;

    cin >> n;
    while(n--){
        cin >> weather1 >> weather2;
        if(weather1 == "sol") { // if when at home it's not raining
            // if at work it's raining
            if(weather2 == "chuva") {
                // check if there's already a umbrella at work, if it doesn't, buy one
                if(auxUW == 0) {
                    uW++; // buy one at work
                    auxUH++; // take that umbrella home
                } else {
                    auxUH++; // take one umbrella that it's already at work to home
                    auxUW--; // remove that umbrella from work
                }
            }
        } else {  // if at home it's raining
            // check if there's a umbrella at home, if there is:
            if(auxUH != 0) {
                // check if at work is raining, if it's not raining, then, there's no need to take umbrella back home
                if(weather2 == "sol") {
                    auxUH--; // remove that from home, and take it work
                    auxUW++; // put it at work
                }
                // if it's raining at work, it means that the umbrella will be take to work and then return back home,
                // so there's no need to remove that from home and place it at work and vice versa in this case.
            } else {
                uH++; // in case there's any umbrella at home, then buy one
                // first check if it's going to rain at work, if that's the case, then increment the amount of umbrella
                // at home, since we are going to take it to work and return back home with it.
                if(weather2 == "chuva") {
                    auxUH++;
                } else {
                    // otherwise, number of umbrella at work increase, since we don't return it
                    auxUW++;
                }
            }
        }
    }

    cout << uH << " " << uW << endl;
    return 0;
}
