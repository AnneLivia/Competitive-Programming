#include <iostream>
#include <vector>

using namespace std;

vector<long long int>v;
int tam;

int binary(long long int x) {
    int ini = 0, fim = tam, mid;
    while(ini <= fim) {
        mid = (fim + ini) >> 1;
        if(v[mid] == x)
            return v[mid];
        else if (v[mid] > x) {
            fim = mid - 1;
        } else if (v[mid] < x) {
            ini = mid + 1;
        }
    }
    return v[mid];
}

int main()
{
    int n;
    long long k, value, p;

    cin >> n;
    tam = n;
    while(n--) {
        cin >> value;
        v.push_back(value);
    }

    cin >> k;

    for ( int i = 0; i < tam; i++) {
        p = binary(k - v[i]);
        if(p + v[i] == k) {
            cout << v[i] << " " << p << endl;
            break;
        }
    }
    return 0;
}
