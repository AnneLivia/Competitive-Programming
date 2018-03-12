#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>


using namespace std;

int main()
{
    long long int qtdCity, qtdPeople, height;
    cin >> qtdCity;
    while(qtdCity--) {
        vector<long long int>heights;
        cin >> qtdPeople;
        while(qtdPeople--) {
            scanf("%d",&height);
            heights.push_back(height);
        }
        sort(heights.begin(),heights.end());
        for(int i = 0; i < heights.size(); i++) {
            printf("%d",heights[i]);
            if(i < heights.size() - 1)
                printf(" ");

        }
        printf("\n");
    }
    return 0;
}
