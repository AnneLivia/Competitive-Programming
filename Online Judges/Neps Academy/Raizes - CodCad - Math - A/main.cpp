//Codigo de exemplo
#include<iostream>
#include <cmath>

using namespace std;

int main(){
  int qtd;
  double num;
  cin >> qtd;
  while(qtd--) {
    cin >> num;
    cout.precision(4);
    cout.setf(ios::fixed);
    cout << sqrt(num) << endl;
  }
  return 0;
}
