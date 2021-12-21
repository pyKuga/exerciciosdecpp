#include <iostream>

/*void Swap(int &x, int &y){
    int aux;
    aux = x;
    x = y;
    y = aux;
}*/

// pega o valor inputado no for
void GetValue(int n, int Arranjo[]){
    for(int i=0;i<n;i++){
        std::cin >> Arranjo[i];
    }
}
// inicio é o inicio da função recursiva, não do BO da lista
int BinarySearch(int Lista[], int Alvo, int Left,int Right){
    int Meio = (Left + Right)/2;
    if(Lista[Meio]==Alvo){
        return Meio;
    }
    if(Left >= Right){
        return -1;
    }
    if(Lista[Meio] > Alvo){
        BinarySearch(Lista,Alvo, Left, Meio-1);
    }
    else{
        BinarySearch(Lista,Alvo, Meio+1, Right);
    }
}

int main(){
    int n, k;
    std::cin >> n;
    int Lista[n];
    GetValue(n,Lista);
    
    std::cin >> k;
    int Verify[k],Index;
    GetValue(k,Verify);
    
    //variavel auxiliar: vai servir p/ contar o numero de numeros diferentes
    int PseudoSize =1; 
    for(int i=1; i < n;i++){
        if(Lista[i]!=Lista[i-1]){
            PseudoSize+=1;
        }
    }
    
    int AbstIndex[PseudoSize];
    int Numeros[PseudoSize];
    
    Numeros[0] = Lista[0];
    AbstIndex[0] = 0;
    int Var = 1;
    for(int i=1; i < n;i++){
        if(Lista[i]!=Lista[i-1]){
            AbstIndex[Var] = i;
            Numeros[Var] = Lista[i];
            Var += 1;        
        }
        
    }


    
    
    for(int i = 0; i<k;i++){
        Index=BinarySearch(Numeros,Verify[i],0,PseudoSize-1);
        if(Index!=-1){
            std::cout << AbstIndex[Index] << " ";
        }
        else{
            std::cout << Index << " ";
        }
    }


}