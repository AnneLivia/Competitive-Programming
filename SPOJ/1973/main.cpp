#include <iostream>
#include <cstdio>
#include <vector>
#include <numeric>
#include <set>

using namespace std;

int main() {

  long long n;
  int i;
  long long total = 0;
  set <long long> s;

  scanf("%lld",&n);

  long long v[n];

  for ( i = 0; i < n; i++) {
    scanf("%lld",&v[i]);
  }

  i = 0;

  while(i >= 0 && i < n) {
    s.insert(i);
    if(v[i] & 1) {
        if(v[i])
            v[i]--;
        i++;
    } else {
        if(v[i])
            v[i]--;
        i--;
    }
  }

  for ( int i = 0; i < n; i++) {
    total+=v[i];
  }

  cout << s.size() << " " << total << "\n";

  return 0;
}
