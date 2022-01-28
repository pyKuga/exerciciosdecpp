#include <iostream>
#include <bits/stdc++.h>

#define INF 1e5;



int main(){
    int n;
    std::cin >> n;
    int Troco[n];
    Troco[0] = 1; // 1 de troco
    Troco[1] = 2; // 2 de troco
    Troco[2] = 1; // 3 de troco
    Troco[3] = 1; // 4 de troco
    for(int i=4;i<n;i++){
        int Analise[3] = {Troco[i-1], Troco[i-3], Troco[i-4]};
        int* Validador = std::min_element(Analise,Analise+3);
        Troco[i] = 1 + *Validador;
    }
    std::cout << Troco[n-1];


}
