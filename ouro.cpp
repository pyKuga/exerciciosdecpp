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

void PrintVec(std::vector<int> Vec){
    for(auto it = Vec.begin(); it != Vec.end() ; it++){
        std::cout << *it << " ";
    }
}

int Resolve(vector<int> Pesos, int W, int n){
    vector <vector<int>> K(W+1,vector<int>(n+1));
    for(int j = 1;j <= n;j++){
        for(int w= 1; w <=W;w++){
            if(Pesos[j-1] > w){
                K[w][j]= K[w][j-1];
            }
            else{
                K[w][j]=max(K[w][j-1],K[w-Pesos[j-1]][j-1]+Pesos[j-1]);
            }
        }
    }
   return K[W][n];
}

// tem q tirar do esquema [i][j]
int main(){
    int W,n;
    cin >> W >> n;
    vector <int> Pesos = GetValue(n);
    //PrintVec(Pesos);
    
    cout << Resolve(Pesos,W,n);

    /*for(int i=0;i<W+1;i++){
        for(int j=0;j<n+1;j++){
            cout<< K.at(j*W+i) << " ";
        }
    cout << "\n";
    }*/
}