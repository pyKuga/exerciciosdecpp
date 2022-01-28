#include<iostream>
#include<vector>
#include<queue>
int Count = 0;

std::vector<int> GetValue(int n){
    std::vector<int> Vetor(n,0);
    int Valor;
    for(int i = 0; i<n; i++){
        std::cin  >> Valor;
        Vetor.at(i) = Valor;
    }
    return Vetor;

}

void Heapificador(std::vector<int> *Vetor,int i,std::queue<std::pair<int,int>> *Ponteiro){
    int Tamanho = Vetor->size();
    int Menor = i;
    int Esquerda = 2*i+1;
    int Direita = 2*(i+1);
    if(Esquerda < Tamanho && Vetor->at(Esquerda) < Vetor->at(Menor)){
        Menor = Esquerda;
    }
    if(Direita < Tamanho && Vetor->at(Direita) < Vetor->at(Menor)){
        Menor = Direita;
    }

    if(Menor != i){
        std::swap(Vetor->at(i),Vetor->at(Menor));
        Ponteiro->push(std::pair<int,int> (i,Menor));
        Heapificador(Vetor,Menor,Ponteiro);
        Count += 1;
    }
    
    
    
}

void HeapBuild(std::vector<int> *Vetor,std::queue<std::pair<int,int>> *Ponteiro){
    for(int i = Vetor->size(); i >=0; i--){
        Heapificador(Vetor,i,Ponteiro);
    }

}


int main(){

    int n;
    std::queue<std::pair<int,int>> Pares;
    std::cin >> n;
    std::vector<int> Array = GetValue(n);
    HeapBuild(&Array,&Pares);
    std::cout << Count << std::endl;
    while(!Pares.empty()){
        std::cout << Pares.front().first << " " << Pares.front().second << std::endl;
        Pares.pop();
    }





}