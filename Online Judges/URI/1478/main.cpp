#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int n, cima, baixo;
    vector<vector<int>>v;
    while(cin >> n && n) {
        for ( int i = 0; i < n; i++) {
            cima = 0;
            baixo = i + 1;
            for ( int j = 0; j < n; j++) {
                if(j != 0)
                    cout << " ";
                if(j >= i)
                    printf("%3d",++cima);
                else if (j < i)
                    printf("%3d",baixo--);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
