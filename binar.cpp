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
    int Verify[k],Index[k];
    GetValue(k,Verify);
    
    for(int i = 0; i<k;i++){
        Index[i]=BinarySearch(Lista,Verify[i],0,n-1);
        std::cout << Index[i] << " ";
    }


}