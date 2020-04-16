#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int qtd, d,c, pos;
    double bigger;
    cin >> qtd;
    for ( int i = 0; i < qtd; i++) {
      cin >> d >> c;
      if(i == 0)
        bigger = c * log10(d);
      if(bigger < c * log10(d)) {
        bigger = c * log10(d);
        pos = i;
      }
    }
    cout << pos << endl;
    return 0;
}
