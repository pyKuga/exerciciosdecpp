#include <iostream>
int Fibo(int n){
  int F_ant, F_dps,i,Inter;
  if(n==0){
      return 0;
  }
  else{
    F_ant = 0;
    F_dps = 1;
    for(i=1;i<n;i++){
        Inter = F_dps;
        F_dps = F_dps + F_ant;
        F_ant = Inter;
    }
    return F_dps;
  }
}

int main(){
  int n, F_n;
  std::cin >> n;
  F_n = Fibo(n);
  std::cout << F_n;
  return 0;
}
