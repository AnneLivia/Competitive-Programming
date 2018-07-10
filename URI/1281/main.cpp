#include <iostream>
#include <map>
#include <cstdio>

using namespace std;

int main()
{
    int idaAFeira, qtdProdDisponiveis, qtdProdComprados, qtdComprado;
    string nomeProduto;
    float preco, precoTotal;

    cin >> idaAFeira;

    while(idaAFeira--) {
        precoTotal = 0.0;
        cin >> qtdProdDisponiveis;
        map<string,float>produtos;
        while(qtdProdDisponiveis--) {
            cin >> nomeProduto >> preco;
            produtos.insert(make_pair(nomeProduto,preco));
        }
        cin >> qtdProdComprados;
        while(qtdProdComprados--) {
            cin >> nomeProduto >> qtdComprado;
            if(produtos.find(nomeProduto) != produtos.end()) {
                precoTotal+=produtos.at(nomeProduto) * qtdComprado;
            }
        }
        printf("R$ %.2f\n",precoTotal);
    }
    return 0;
}
