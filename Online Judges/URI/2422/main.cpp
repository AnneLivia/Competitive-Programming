#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

vector<int>v;

int binary(int k, int tn) {
    int mid, fim, inicio;
    inicio = 0;
    fim = tn - 1;
    while(inicio <= fim) {
        mid = (inicio + fim) / 2;

        if(v[mid] == k) {
            break;
        } else if (k > v[mid]) {
            inicio = mid + 1;
        } else {
            fim = mid - 1;
        }
    }
    return mid;
}

int main()
{
    int tn, n, k;
    scanf("%d",&tn);
    for ( int i = 0; i < tn; i++) {
        scanf("%d",&n);
        v.push_back(n);
    }
    scanf("%d",&k);

    for ( int i = 0; i < tn; i++) {
        int b = binary((k - v[i]), tn);
        if(v[i] + v[b] == k) {
            printf("%d %d\n",v[i],v[b]);
            break;
        }
    }

    return 0;
}
