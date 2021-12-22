#include <iostream>

/* FUNCOES AUXILIARES */ 
//-----------------------------------------------------------------------------------------------
// Troca dois numeros O(C)
void Swap(int &x, int &y){
    int aux;
    aux = x;
    x = y;
    y = aux;
}

// Imprime um array na tela O(n)
void PrintArray(int Array[], int n){
    for(int i = 0; i <n; i++){
        std::cout << Array[i] << " ";
    }
    std::cout << "\n";
}

// Pega o valor digitado pelo user O(n)
void GetValue(int n, int Arranjo[]){
    for(int i=0;i<n;i++){
        std::cin >> Arranjo[i];
    }
}

// Preenche um Array com zeros O(n)
void Preenche(int Array[],int n, int Preenche){
    for(int j=0; j < n; j++){
        Array[j] = Preenche;
    }
}

// Verifica o valor máximo em um array e retorna o índice: O(n)
int Maximum(int Array[], int n){
    int Maximo = 0;
    for(int j=1; j<n; j++){
        if(Array[j] > Array[j-1]){
            Maximo = j;
        }

    }
    return Maximo;
}

// Verifica se todos os valores de um array são um número
int Verifica(int Array[], int n, int Target){
    int i = 0;
    for(int i =0; i < n; i++){
        if(Array[i]!=Target){
            return 0;
        }
    }
    return 1;
}
//-----------------------------------------------------------------------------------------------

// FUNCOES DE MANIPULACAO 
//-----------------------------------------------------------------------------------------------

// Reduz o tamanho do arranjo - O(n)
int GetReducedSize(int Array[], int n){
    int PseudoSize =1; 
    for(int i=1; i < n;i++){
        if(Array[i]!=Array[i-1]){
            PseudoSize+=1;
        }
    }
    return PseudoSize;
}

//Reduz o array repetido da lista para outro array menor (sort no python) - O(n)
void CheckArray(int Somas[], int Abstract[], int Array[],int n){
    int Var = 0;
    for(int i=1; i < n;i++){
        if(Array[i]!=Array[i-1]){
            Abstract[Var+1] = i;
            Var += 1;    
        }
        else{
            Somas[Var] += 1;
        }
    }
}



//-----------------------------------------------------------------------------------------------

/*QUICK SORT*/

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

}

int main(){
    int n;
    std::cin >> n;
    int Lista[n];
    GetValue(n,Lista);
    QuickSort(Lista,0,n-1);

    int PseudoSize = GetReducedSize(Lista,n);

    int AbstIndex[PseudoSize];
    int Somas[PseudoSize];

    Preenche(AbstIndex, PseudoSize,0);
    Preenche(Somas, PseudoSize,1);
    CheckArray(Somas,AbstIndex,Lista,n);

    
    int Maximo = Maximum(Somas,PseudoSize);
    int VF = Verifica(Somas,PseudoSize,1);
    if(VF==1){
        std::cout << 0;
    }
    else{
        std::cout << AbstIndex[Maximo]+1;
    }



    


}

