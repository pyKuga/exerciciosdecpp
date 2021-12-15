#include <iostream>
#include <vector>


int Devolve(int Troco){
    int Qtd,Indice, NAT;
    // define o tipo das moedas    
    std::vector<int> Moedas(3);
    Moedas[0] = 10; Moedas[1] = 5; Moedas[2] = 1;
    Qtd = 0;
    NAT = 0;
    Indice = 0;
    while(Troco !=0){
        NAT = Troco / Moedas[Indice];
        Qtd += NAT;
        Troco = Troco - NAT*Moedas[Indice];
        Indice += 1;
    }
    return Qtd;
}



int main(){
    int Troco, Quantidade;

    std::cin >> Troco;
    Quantidade = Devolve(Troco);
    std::cout << Quantidade;
    

}