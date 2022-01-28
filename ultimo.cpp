#include <iostream>
#include <cstring>

using namespace std;


int Distancia(string Letra1, string Letra2){
    int Tamanho1,Tamanho2,Custo;
    Tamanho1 = Letra1.length();
    Tamanho2 = Letra2.length();
    int Matriz[Tamanho1+1][Tamanho2+1] = {0};
    memset(Matriz,0, sizeof Matriz);
    for(int i=1; i <= Tamanho1; i++){Matriz[i][0] = i;}
    for(int i=1; i <= Tamanho2; i++){Matriz[0][i] = i;}
    for(int i=1; i <= Tamanho1; i++){
       for(int j=1;j <= Tamanho2; j++){
           Custo = !(Letra1[i-1]==Letra2[j-1])*1;
           int Analise = min(Matriz[i-1][j],Matriz[i][j-1]);
           Matriz[i][j] = min(Analise+1,Matriz[i-1][j-1]+Custo);
       } 
    }
    return Matriz[Tamanho1][Tamanho2];
}

int main(){
    string Frase1, Frase2;
    getline(cin,Frase1);
    getline(cin,Frase2);
    cout << Distancia(Frase1,Frase2);
}