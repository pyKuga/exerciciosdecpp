#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <string>

//Estruturas de dados
struct Consulta{
    std::string Comando, Nome;
    int Numero;  
};

//funcoes de baixo p/ frente
void Processamento(std::unordered_map<int,std::string> *Tabela,std::queue<Consulta*> *Fila){
    while(!Fila->empty()){
        Consulta* Atual = Fila->front();
        Fila->pop();
        std::unordered_map<int,std::string>::const_iterator Procura = Tabela->find(Atual->Numero);
        if(Atual->Comando == "add"){
            if(Procura==Tabela->end()){
                Tabela->emplace(Atual->Numero,Atual->Nome);
            }
            else{
                Tabela->at(Atual->Numero) = Atual->Nome;
            }
        }
        else if(Atual->Comando == "del"){
            Tabela->erase(Atual->Numero);
        }
        else if(Atual->Comando == "find"){
            if(Procura==Tabela->end()){
                std::cout<<"not found" << std::endl;
            }
            else{
                std::cout << Procura->second << std::endl;
            }
        }
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
    if(Atual->Comando == "add"){
        Atual->Nome = Palavras.at(2);
        Atual->Numero = std::stoi(Palavras.at(1));
    }
    else if(Atual->Comando == "del"){
        Atual->Numero = std::stoi(Palavras.at(1));
    }
    else if(Atual->Comando == "find"){
        Atual->Numero = std::stoi(Palavras.at(1));
    }
    else{
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
    int n;
    std::cin >> n;
    std::queue<Consulta*> CLista;
    std::unordered_map<int,std::string> Hash;
    GetQueries(n,&CLista);
    Processamento(&Hash,&CLista);    
}
