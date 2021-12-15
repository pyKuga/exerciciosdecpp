#include <iostream>

long long GCD(long long a, long long b){
  long long Fluxo, Alvo;
  Fluxo = a % b;
  if(Fluxo != 0){
    Alvo = GCD(b, Fluxo);
    return Alvo;
  }
  else{
    return b;
  }


}

long long LCM(long long a,long long b){
  long long MDC;
  long long MMC;
  MDC = GCD(a,b);
  MMC = a*b/MDC;
  return MMC;

}

int main(){
  long long a, b;
  long long Res;
  std::cin >> a;
  std::cin >> b;
  Res = LCM(a,b);
  std::cout << Res;
  return 0;
}

