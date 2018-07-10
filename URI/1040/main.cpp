#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main() {
    double n1,n2,n3,n4, media;
    cin >> n1 >> n2 >> n3 >> n4;

    media = ((n1 * 2) + (n2 * 3) + (n3 * 4) + (n4 * 1))/(2+3+4+1);
    printf("Media: %.1f\n",media);
    if(media >= 7.0)
        cout << "Aluno aprovado.\n";
    else if(media < 5.0)
        cout << "Aluno reprovado.\n";
    else if(media >= 5.0 && media <= 6.9)
    {
        double nota;
        cout << "Aluno em exame.\n";
        cin >> nota;
        printf("Nota do exame: %.1f\n",nota);
        media = (media + nota) / 2;
        if(media >= 5.0)
            cout << "Aluno aprovado.\n";
        else if(media <= 4.9)
            cout << "Aluno reprovado.\n";
        printf("Media final: %.1f\n",media);
    }
	return 0;
}
