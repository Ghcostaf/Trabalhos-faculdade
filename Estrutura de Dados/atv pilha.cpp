#include <iostream>
#include <vector>
#include <list>


class PilhaVetor {

private:
    std::vector<int> data; 


public:

    void push(int value) {

        data.push_back(value);
    }
    
    void pop() {

        data.pop_back();
    }
    
    
    int top() const {

        return data.back();
    }
    
    
    bool empty() const {

        return data.empty();
    }
    
   
    int size() const {

        return data.size();
    }
};


class PilhaLista {


private:

    std::list<int> data;  

public:
    
    void push(int value) {

        data.push_back(value);
    }
    
    
    void pop() {

        data.pop_back();
    }
    
    
    int top() const {

        return data.back();
    }
    
    
    bool empty() const {

        return data.empty();
    }
    
    
    int size() const {

        return data.size();
    }
};

int main() {
    
    PilhaVetor pilhaVetor;

    pilhaVetor.push(10);
    
    pilhaVetor.push(20);
    
    pilhaVetor.push(30);
    
    std::cout << "Topo da pilha: " << pilhaVetor.top() << std::endl;
    
    pilhaVetor.pop();
    
    std::cout << "Topo da pilha: " << pilhaVetor.top() << std::endl;
    std::cout << "Pilha vazia? " << (pilhaVetor.empty() ? "Sim" : "Nao") << std::endl; 
    std::cout << "Tamanho da pilha: " << pilhaVetor.size() << std::endl;
    
    
    PilhaLista pilhaLista;
   
    pilhaLista.push(100);
   
    pilhaLista.push(200);
   
    pilhaLista.push(300);
    
    std::cout << "Topo da pilha: " << pilhaLista.top() << std::endl;
    pilhaLista.pop();
    std::cout << "Topo da pilha: " << pilhaLista.top() << std::endl;
    std::cout << "Pilha vazia? " << (pilhaLista.empty() ? "Sim" : "Nao") << std::endl;
    std::cout << "Tamanho da pilha : " << pilhaLista.size() << std::endl;
    
    return 0;
}
