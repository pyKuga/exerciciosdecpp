#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

long long Funcao(const vector<int>& Numeros){
  int Indice1, Indice2, Distancia, i,Zeros;
  long long resultado;
  Indice1 = 1;
  Indice2 = 1;
  Zeros = 0;
  Distancia = Numeros.size();
  for(i=0; i < Distancia;i++){
    if(Numeros[i] == 0){
      Zeros+=1;
    }
  }
  if(Distancia-Zeros==1){
    resultado = 0;
  }
  else{
    for(i=0; i < Distancia; i++){
      if(Numeros[i] > Numeros[Indice1]){
        Indice1 = i;
      }
    }
    for(i=0; i < Distancia; i++){
      if((Numeros[i] > Numeros[Indice2]) && (i != Indice1)){
        Indice2 = i;
      }
    }
    resultado = ((long long)Numeros[Indice1])*Numeros[Indice2];
  }
  return resultado;
}
int main(){
  int Tamanho;
  long long Produto;
  cin >> Tamanho;
  vector<int> Numeros(Tamanho);
  for(int i=0; i < Tamanho; i++){
    cin >> Numeros[i];
  }
  Produto = Funcao(Numeros);
  cout << Produto << "\n";
  return 0;
}
