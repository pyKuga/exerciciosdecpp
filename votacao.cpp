#include <iostream>
#include <map>

// Pega o valor digitado pelo user O(n)
void GetValue(int n, int Arranjo[]){
    for(int i=0;i<n;i++){
        std::cin >> Arranjo[i];
    }
}

/* Troca dois numeros O(C)
void Swap(int &x, int &y){
    int aux;
    aux = x;
    x = y;
    y = aux;
}

//QUICK SORT

int Partition(int Lista[],int Left, int Right){
    int Pivo = Lista[Left];
    int i =Left;
    for(int j = Left+1; j <= Right; j++){
        if(Lista[j]<= Pivo){
            i+=1;
            Swap(Lista[i],Lista[j]);
        }
    }
    Swap(Lista[Left],Lista[i]);
    return i;


}

int QuickSort(int Lista[], int Left, int Right){
    if(Left < Right){
        int Pivo_Indice = Partition(Lista,Left,Right);
        QuickSort(Lista, Left, Pivo_Indice-1);
        QuickSort(Lista, Pivo_Indice+1, Right);
    }
}*/
//map é tipo um dicionario do python, então dá p/ usar como se fosse um contador, fazendo so operações no map em si, sem precisar passar pelo quick sort
bool Analise(std::map<int,int>Somas,int Lista[], int n){
    bool Flag = 0;
    for(int i =0; i<n;i++){
        Somas[Lista[i]] += 1;
    }
    for (std::map<int,int>::iterator i=Somas.begin(); i!=Somas.end(); i++){
        if(i->second > n/2){
            Flag = 1;
            break;
        }
    }
    return Flag;


}



int main(){
    int n,Soma;
    std::cin >> n;
    int Lista[n];
    std::map<int,int> Somas;
    GetValue(n,Lista);
    //QuickSort(Lista,0,n-1);

    std::cout << Analise(Somas,Lista,n);



}

