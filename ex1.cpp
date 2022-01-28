#include <iostream>
#include <stack>
#include <string>

using namespace std;


void Avalia(string Entrada){
    stack<char> Carregador; // Cria o stack de letras
    stack<int> Indices; //cria o stack de indices
    bool Erro=0; // Flag de erro p/ carregador vazio
    int i = 0; // Contador da posição
    for(string::iterator Caracter=Entrada.begin();Caracter!=Entrada.end();Caracter++){       //itera do começo ao fim da string
        i+=1;
        if(*Caracter=='[' || *Caracter=='{' || *Caracter=='('){
            Indices.push(i); //coloca o indice que pode dar pau
            Carregador.push(*Caracter); // se é [,{ ou ( coloca no stack
        }  
        else{
            if(*Caracter == ']' ||  *Caracter == '}' ||  *Caracter == ')'){
                if(Carregador.empty()){
                    Indices.push(i);
                    Erro=1;
                    break;
                }
                char Top = Carregador.top();
                Carregador.pop();
                if((Top=='[' && *Caracter != ']')||(Top=='(' && *Caracter != ')')||(Top=='{' && *Caracter != '}')){
                    Erro = 1;
                    Indices.push(i);
                    break;
                }
                Indices.pop();
            }
        }
    }
    
    
    if(Carregador.empty() && Erro == 0){cout << "Success";}
    else{cout << Indices.top();}

}


int main(){
    string Entrada;
    getline(cin,Entrada);
    Avalia(Entrada);
    
}