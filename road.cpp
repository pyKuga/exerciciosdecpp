#include <iostream>


int Paradas(int d,int m,int n,int X[]){
    if(d==m){
        return 0;
    }
    int Atual=0, Ultima=0, Numero =0;
    
    while(Atual <= n){
        Ultima = Atual;
        while(Atual <= n && X[Atual+1]-X[Ultima] <= m){
            Atual += 1;
        }
        if(Ultima == Atual){
            return -1;
        }
        if(Atual<=n){
            Numero +=1;
        }
    }
    return Numero;


}


int main(){
    int d,m,n,Nparadas;
    std::cin >> d;
    std::cin >> m;
    std::cin >> n;
    int X[n+2];
    X[0] =0;
    X[n+1]=d; 
    for(int i=1; i<n+1; i++){
        std::cin >> X[i];
    }

    Nparadas = Paradas(d,m,n,X);
    std::cout << Nparadas;
}