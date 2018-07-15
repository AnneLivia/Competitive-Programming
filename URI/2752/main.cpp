#include <iostream>
#include <cstdio>


using namespace std;

int main()
{
    char frase[51] = "AMO FAZER EXERCICIO NO URI";
    printf("<%s>\n",frase);
    printf("<%30s>\n",frase);
    printf("<%.20s>\n",frase);
    printf("<%-20s>\n",frase);
    printf("<%-30s>\n",frase);
    printf("<%.30s>\n",frase);
    printf("<%30.20s>\n",frase);
    printf("<%-30.20s>\n",frase);
    return 0;
}
