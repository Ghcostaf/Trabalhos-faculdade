
#include <iostream>


class LinkedList {

    private:

        struct Node {
            int data;
            Node* next;
        };
        
        Node* head;
        
        int size;

    public:

        LinkedList() {
            head = nullptr;
            size = 0;
        }



        bool isEmpty() {
            return (head == nullptr);
        }


        int getSize() {
            return size;
        }


        int getValue(int pos) {
            if (pos >= size || pos < 0) {
                std::cerr << "Error: posicao invalida" << std::endl;
                exit(1);
            }
            Node* current = head;
            for (int i = 0; i < pos; i++) {
                current = current->next;
            }
            return current->data;
        }


        void setValue(int pos, int value) {
            if (pos >= size || pos < 0) {
                std::cerr << "Error: posicao invalida" << std::endl;
                exit(1);
            }
            Node* current = head;
            for (int i = 0; i < pos; i++) {
                current = current->next;
            }
            current->data = value;
        }


        void insert(int pos, int value) {
            if (pos > size || pos < 0) {
                std::cerr << "Error: posicao invalida" << std::endl;
                exit(1);
            }
            Node* newNode = new Node;
            newNode->data = value;
            if (pos == 0) {
                newNode->next = head;
                head = newNode;
            } else {
                Node* current = head;
                for (int i = 0; i < pos - 1; i++) {
                    current = current->next;
                }
                newNode->next = current->next;
                current->next = newNode;
            }
            size++;
        }


        void remove(int pos) {
            if (pos >= size || pos < 0) {
                std::cerr << "Error: posicao invalida" << std::endl;
                exit(1);
            }
            Node* toDelete;
            if (pos == 0) {
                toDelete = head;
                head = head->next;
            } else {
                Node* current = head;
                for (int i = 0; i < pos - 1; i++) {
                    current = current->next;
                }
                toDelete = current->next;
                current->next = toDelete->next;
            }
            delete toDelete;
            size--;
        }


        void print() {
            Node* current = head;
            std::cout << "[ ";
            while (current != nullptr) {
                std::cout << current->data << " ";
                current = current->next;
            }
            std::cout << "]" << std::endl;
        }
};

int main() {
    LinkedList list;

    std::cout << "Lista está vazia: " << list.isEmpty() << std::endl;
    
    std::cout << "Tamanho da lista: " << list.getSize() << std::endl;
    
    list.insert(0, 5);
    
    list.insert(1, 10);
    
    list.insert(1, 7);
    
    list.print();
    
    std::cout << "Tamanho da lista: " << list.getSize() << std::endl;
    
    list.remove(1);
    
    list.print();
    
    list.setValue(0, 15);
    
    std::cout << "valor da posicao 0: " << list.getValue(0) << std::
