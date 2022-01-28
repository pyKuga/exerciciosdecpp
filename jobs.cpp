#include <iostream>
#include<algorithm>
#include<vector>
#include<queue>
class Thread{
    public:
        long long Time;
        long long Key;
        Thread(int Time,int Key):Time(Time),Key(Key){}
};
bool operator < (const Thread& A, const Thread& B)
{
    if(A.Time == B.Time){
        return A.Key > B.Key;
    }
    else{
        return A.Time > B.Time;
    }
}

class Processador{
    public:
        long long ThreadNumber;
        std::vector<Thread*> Threads;
        std::priority_queue<Thread, std::vector<Thread>,std::less<std::vector<Thread>::value_type>> FilThreads;
    Processador(){
        this->ThreadNumber=1;
    }
    void Ajuste(long long n){
        this->ThreadNumber = n;
        Threads.resize(this->ThreadNumber);
    }
    void CreateThreads(){
        for(int i = 0; i < this->ThreadNumber;i++){
            Thread* Atual = new Thread(0,i);
            Threads.at(i) = Atual;
            FilThreads.push(*Atual);
        }
    }


    //Faz o cálculo do processamento e utiliza o mínimo tempo entre elas e note a ausência de um if ae.
    void Processing(std::queue<long long> Tempos, long long m){
        long long AtualProcessTime; //tempo do processo puxado
        long long ID_Thread; //id da thread
        long long UltimoTempo = 0; //o ultimo tempo registrado
        while(!Tempos.empty()){
            AtualProcessTime = Tempos.front();
            Tempos.pop();
            ID_Thread = FilThreads.top().Key;
            FilThreads.pop();
            Thread* Thread_Atual = Threads.at(ID_Thread);
            std::cout << ID_Thread << " " << Thread_Atual->Time << std::endl;
            Thread_Atual->Time += AtualProcessTime;
            FilThreads.push(*Thread_Atual);
        }
    }

};

//Pega os tempos e joga p/ uma fila (melhor que pegar um vetor wtf);
std::queue<long long> GetTimes(long long m){
    std::queue<long long> Tempos;
    long long Tempo = 0;
    for(int i=0;i<m;i++){
        std::cin >> Tempo;
        Tempos.push(Tempo);
    }
    return Tempos;
}



int main(){
    long long n, m;
    std::cin >> n >> m;
    Processador Intel;
    Intel.Ajuste(n);
    Intel.CreateThreads();
    std::queue<long long> ProsTime = GetTimes(m);
    Intel.Processing(ProsTime,m);
}