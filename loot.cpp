#include <iostream>
#include <iomanip>


void Ordena(int N, double VPR[]){
    double Minimo;
    double SwapD[3];
    // ordenando a razão
    bool flag = false;
    int Indice;
    for(int i=2; i <N-3; i=i+3){
        Minimo = VPR[i];
        for(int j=i+3; j<N;j=j+3){
           if(Minimo > VPR[j]){
               flag = true;
               Minimo = VPR[j];
               Indice = j;
           }            
        }
        if(flag){
            for(int k=0;k<3;k++){
                SwapD[2-k] = VPR[i-k];
                VPR[i-k] = VPR[Indice-k];
                VPR[Indice-k] = SwapD[2-k] ;
            }
            flag = false;
        
        }
    }
}
void Aparece(int N,double VPR[]){
    for(int i=0; i<N;i=i+3){
        for(int j=0;j<3;j++){
            std::cout << VPR[i+j] << " ";
        };
        std::cout << "\n";
    }
}


double Sacola(int N,int W,double VPR[]){
    double Valor=0;
    double Minimo=0;

    for(int i =0; i<N;i=i+3){
        if(W==0){
            return Valor;
        }
        Minimo=std::min(VPR[(N-i-2)],(double)W);
        Valor += Minimo*VPR[N-i-1];
        W -= Minimo;

    }
    return Valor;
}

int main(){
    int n, W,N;

    std::cin >> n >> W;
    double VPR[3*n];
    double Valor;
    N = 3*n;
    


    for(int i=0; i<N; i=i+3){
        std::cin >> VPR[i] >> VPR[i+1]; // entra valor e peso
        VPR[i+2] = VPR[i]/VPR[i+1];
    }
    Ordena(N,VPR);
    Valor=Sacola(N,W,VPR);
    std::cout << std::fixed;
    std::cout << std::setprecision(4);
    std::cout << Valor;




    
   
  
    

}