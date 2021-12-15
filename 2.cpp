#include <iostream>
int FiboMod10(long n){
  int F_ant, F_dps,Inter;
  long i;
  F_ant = 0;
  F_dps = 1;
  for(i=1;i<n;i++){
    Inter = F_dps;
    F_dps = (F_dps + F_ant) % 10 ;
    F_ant = Inter;
  }
  return F_dps;
}

int main(){
  long n;
  int F_n;
  std::cin >> n;
  // F_n = Fibo(n);
  F_n = FiboMod10(n);
  std::cout << F_n;
  

  return 0;
}