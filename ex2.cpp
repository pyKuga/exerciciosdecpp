//um código de:
// jacaranda - a serpente do sigilo do pecado

#include <iostream> 
#include <map>
#include <vector>
#include <queue>

// cria uma classe nó de árvore com alguns atributos
/*
-Chave: nome do nó
-Pai: quem é o nó pai
-vetor de nós de filhos

-todo nó é inicializado com pai nulo (caso seja raiz não se altera o valor)

método: define o pai do nó
*/
class Node
{
    public:
    int Chave;
    Node *Pai;
    std::vector<Node*> Filhos;
    int Level;

    Node(){
        this->Pai=nullptr;
    }

    void SetParent(Node *NoPai){
        Pai = NoPai;
        Pai->Filhos.push_back(this);
    }
    

};

//imprime dois atributos do nó: a chave e o numero de filhos
void PrintNode(std::vector<Node*> Nodes){
    for(int i = 0; i<Nodes.size();i++){
        std::cout << "Chave: " << Nodes.at(i)->Chave << " #Filhos: " << Nodes.at(i)->Filhos.size() << std::endl;
    }
}


//gera um vetor com os nós da árvore. 
std::vector<Node*> TreeGen(int n, int *RootIndex){
    std::queue<int> Pais;
    std::vector<Node*> Nos;
    
    for(int Item = 0; Item <n; Item++){
        Node* Atual = new Node();
        Atual->Chave = Item;
        int ChaveDoPai;
        std::cin >> ChaveDoPai;
        Pais.push(ChaveDoPai);
        Nos.push_back(Atual);
    }   

    for(int Item = 0; Item <n; Item++){
        int ParentIndex = Pais.front();
        Pais.pop();
        if(ParentIndex >=0){
            Nos.at(Item)->Pai = Nos.at(ParentIndex);
            Nos.at(ParentIndex)->Filhos.push_back(Nos.at(Item));
        }
        else{
            *RootIndex = Item;
        }
    }
    return Nos;
    
}


//define a altura da árvore
// usa uma fila p/ analisar nó a nó, empurra os filhos p/ fila e determina o nível de cada filho
int Altura(std::vector<Node*> Nodes, int RootIndex,int n){
    std::queue<Node*> Fila;
    Nodes.at(RootIndex)->Level = 1;
    Fila.push(Nodes.at(RootIndex));
    int Height = 0;
    while(!Fila.empty()){
        Node* Atual = Fila.front();
        if(!Atual->Filhos.empty()){
            for(std::vector<Node*>::iterator it = Atual->Filhos.begin(); it != Atual->Filhos.end();it++){
                Fila.push(*it);
                (*it)->Level =  (Atual->Level) + 1;
                //std::cout << "Chave do Atual: "<<Atual->Chave << " Nivel do atual: " << Atual->Level << " Chave filho: " << (*it)->Chave << " Nivel Filho " << (*it)->Level <<std::endl;
                if((*it)->Level > Height){
                    Height = (*it)->Level;
                }
            }
        }
        Fila.pop();
    }
    return Height;


}

int BFS(Node* Atual){if(Atual->Pai !=nullptr){}}

int main(){
    int n,Insert;
    std::cin >> n;
    std::vector<Node*> Nodes;
    int RootIndex;
    Nodes = TreeGen(n, &RootIndex);
    //PrintNode(Nodes);
    std::cout << Altura(Nodes,RootIndex,n);
}





    
    /*int Array[n];
    std::map<int,int> Mapa;
    for(int i = 0; i < n; i++){
        std::cin >> Insert;
        Mapa[Insert] += 1;
        Array[i] = Insert;
    }
    int Soma = 0;
    for(std::map<int,int>::iterator it=Mapa.begin(); it!=Mapa.end(); it++){
        Soma += it->second - 1;
        //std::cout << it->second <<std::endl;
    }
    std::cout << n - Soma;*/