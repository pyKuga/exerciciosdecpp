#include <iostream>
#include <vector>
using namespace std;
// Pega o valor digitado pelo user O(n)
vector<int> GetValue(int n){
    vector <int> Vetor(n);
    int Temp;
    for(int i=0;i<n;i++){
        cin >> Temp;
        Vetor[i]=Temp;
    }
    return Vetor;
}

int Soma(std::vector<int> Vec){
    int Somaa=0;
    for(auto it = Vec.begin(); it != Vec.end() ; it++){
        Somaa+= *it;
    }
    return Somaa;
}

void PrintVec(std::vector<int> Vec){
    for(auto it = Vec.begin(); it != Vec.end() ; it++){
        std::cout << *it << " ";
    }
}

int Resolve(vector<int> Pesos, int W, int n){
    int Contagem = 0;
    vector <vector<int>> K(W+1,vector<int>(n+1,0));
    for(int i = 1;i < W+1;i++){
        for(int j = 1; j <n+1;j++){
            K[i][j]= K[i][j-1];
            if(Pesos[j-1] <= i){
                int Var = K[i-Pesos[j-1]][j-1]+Pesos[j-1];
                if(Var > K[i][j]){K[i][j] = Var;}
            }
            if(K[i][j]==W){Contagem +=1;}
            //cout << K[i][j] << " " << Contagem <<endl;
            
        }
    }
    return !(Contagem <3);
}

// tem q tirar do esquema [i][j]
int main(){
    int n,W;
    cin >> n;
    vector <int> Pesos = GetValue(n);
    W = Soma(Pesos);
    if(W%3 != 0){
        cout << 0;
    }
    else if(n < 3){
        cout << 0;
    }
    else{
        cout << Resolve(Pesos,W/3,n);
    }

}