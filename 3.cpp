#include <iostream>

long GCD(long a, long b){
  long Fluxo, Alvo;
  Fluxo = a % b;
  if(Fluxo != 0){
    Alvo = GCD(b, Fluxo);
    return Alvo;
  }
  else{
    return b;
  }


}

int main(){
  long a, b;
  long Res;
  std::cin >> a;
  std::cin >> b;
  Res = GCD(a,b);
  std::cout << Res;
  return 0;
}
