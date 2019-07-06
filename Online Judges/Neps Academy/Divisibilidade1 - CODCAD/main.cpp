#include<iostream>

using namespace std;

int main(){
  string n;
  int d2, d3 = 0, d5;

  cin >> n;

  d2 = n[(int)n.size() - 1] -'0';
  for(int i = 0; i < (int)n.size(); i++)
    d3 += n[i] - '0';

  d5 = n[(int)n.size() - 1] - '0';

  if(d2 % 2 == 0)
    cout << "S\n";
  else
    cout << "N\n";

  if(d3 % 3 == 0)
    cout << "S\n";
  else
    cout << "N\n";

  if(d5 == 0 || d5 == 5)
    cout << "S\n";
  else
    cout << "N\n";

}
