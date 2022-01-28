#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1e7


void PrintVecInv(std::vector<int> Vec){
    for(auto it = Vec.rbegin(); it != Vec.rend() ; it++){
        std::cout << *it << " ";
    }
}

std::vector<int> GeraTabela(int n){
    long inf = INF;
    std::vector <int> Tabela;
    Tabela.reserve(n);
    Tabela.assign(n,0);
    for(int i=1;i<n;i++){
        int Var = std::min(Tabela[i/2]+1+inf*((i+1)%2), Tabela[i/3]+1+inf*((i+1)%3));
        Tabela[i]= std::min(Tabela[i-1]+1, Var);
    }
    return Tabela;
}

std::vector<int> Search(std::vector <int> Tabela,int n){
    std::vector <int> Ordem;
    int inf = INF;
    while(n > 1){
        Ordem.push_back(n);
        int Indices[3] {n-1,n/2,n/3};
        int Analise[3] = {Tabela[n-2], Tabela[n/2-1]+inf*(n%2), Tabela[n/3-1]+inf*(n%3)};
        int* Validador = std::min_element(Analise,Analise+3);
        int Var = Validador - Analise;
        n = Indices[Var];
    }
    Ordem.push_back(1);
    return Ordem;
}

int main(){
    size_t n;
    std::cin >> n;
    std::vector<int> Tabela = GeraTabela(n);
    std::cout << Tabela[n-1] << std::endl;
    std::vector<int> Ordem = Search(Tabela, (int)n);
    PrintVecInv(Ordem);

}



