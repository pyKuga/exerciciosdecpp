#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>

struct Consulta{
    std::string Comando, Nome;
    long long Hash;  
};

long long HashOp(std::string Palavra){
    long long Hash=0;
    long long x = 263;
    long long p =  1000000007;
    int i =0;
    long pol;
    for(char C : Palavra){
        pol = std::pow(x,i);
        Hash+=(((int)C)*pol)%p;
        i+=1;
    }
    return Hash;
}


void Adicionar(long long Hash,std::unordered_map<long long, std::vector<std::string>*> *Tabela,Consulta* Atual){
    std::unordered_map<long long, std::vector<std::string>*>::const_iterator Procura = Tabela->find(Atual->Hash);
    std::vector<std::string> *Vetor;
    if(Procura==Tabela->end()){
        Vetor = new std::vector<std::string>;
        Tabela->emplace(Hash,Vetor);
        Vetor->push_back(Atual->Nome);
        }
    else{
        Vetor = Tabela->at(Hash);
        if(std::find(Vetor->begin(), Vetor->end(), Atual->Nome) == Vetor->end()){
            Vetor->push_back(Atual->Nome);  
        }
    }   

}


void Procura(long long Hash,std::unordered_map<long long, std::vector<std::string>*> *Tabela,Consulta* Atual){
    std::unordered_map<long long, std::vector<std::string>*>::const_iterator Procura = Tabela->find(Atual->Hash);
    std::vector<std::string> *Vetor;
    if(Procura==Tabela->end()){std::cout << "no" <<std::endl;}
    else{
        Vetor = Tabela->at(Hash);
        auto ID = std::find(Vetor->begin(), Vetor->end(), Atual->Nome);
        if( ID!= Vetor->end()){
            std::cout << "no" <<std::endl;
        }
        else{
            std::cout << "yes" <<std::endl;;
        }
    }   

}

void Delecao(long long Hash,std::unordered_map<long long, std::vector<std::string>*> *Tabela,Consulta* Atual){
    std::unordered_map<long long, std::vector<std::string>*>::const_iterator Procura = Tabela->find(Atual->Hash);
    std::vector<std::string> *Vetor;
    if(Procura!=Tabela->end()){
        Vetor = Tabela->at(Hash);
        auto ID = std::find(Vetor->begin(), Vetor->end(), Atual->Nome);
        if( ID!= Vetor->end()){
            Vetor->erase(ID);
        }
    }   

}

void Check(long long Hash,std::unordered_map<long long, std::vector<std::string>*> *Tabela,Consulta* Atual){
    std::unordered_map<long long, std::vector<std::string>*>::const_iterator Procura = Tabela->find(Atual->Hash);
    if(Procura==Tabela->end()){std::cout <<std::endl;}
    else{
        std::vector<std::string> *Vetor;
        if(!Vetor->empty()){
            for(std::string Palavra: *Vetor){
                std::cout<<Palavra<< " ";
            }
            std::cout << std::endl;
        }

    }


}

void Processamento(std::unordered_map<long long, std::vector<std::string>*> *Tabela,std::queue<Consulta*> *Fila){
    while(!Fila->empty()){
        Consulta* Atual = Fila->front();
        Fila->pop();
        long long Hash = HashOp(Atual->Nome);
        if(Atual->Comando == "add"){Adicionar(Hash,Tabela,Atual);}
        else if(Atual->Comando == "del"){Delecao(Hash,Tabela,Atual);}
        else if(Atual->Comando == "find"){Procura(Hash,Tabela,Atual);}
        else if(Atual->Comando == "check"){Check(Hash,Tabela,Atual);}
        else{}
    }
}

Consulta* CriaStruct(std::string Query){
    Consulta *Atual = new Consulta;
    std::stringstream Fluxo(Query);
    std::vector<std::string> Palavras;
    std::string Entrada;
    while (Fluxo >> Entrada){
        Palavras.push_back(Entrada);
    }
    Atual->Comando = Palavras.at(0);
    if(Atual->Comando != "check"){
        Atual->Nome = Palavras.at(1);
    }
    else{
        Atual->Hash = std::stoi(Palavras.at(1));
    }
    return Atual;
}

void GetQueries(int n, std::queue<Consulta*> *Fila){
    std::string Query;
    for(int i = 0; i < n; i++){
        std::getline(std::cin >> std::ws, Query);
        Consulta* Operacao = CriaStruct(Query);
        Fila->push(Operacao);
    }
}

int main(){
    int n, m;
    std::cin >> n >> m;
    std::queue<Consulta*> Consultas;
    std::unordered_map<long long, std::vector<std::string>*> Tabela;
    GetQueries(n,&Consultas);
    Processamento(&Tabela,&Consultas);
}