#include "pilaPedido.h"
PilaPedido::PilaPedido(){
    head = nullptr;
    size = 0;
}

PilaPedido::~PilaPedido(){
    NodePedido *current = head;
    while(current != nullptr){
        NodePedido *temp = current;
        current = current->getNext();
        delete temp;
    }
}
void PilaPedido::push(const Pedido data){
    NodePedido *newNode = new NodePedido(data);
    if(head == nullptr){
        head = newNode;
    }
    else{
        newNode->setNext(head);
        head = newNode;
    }
    size++;
}
NodePedido *PilaPedido::pop(){
    if(head == nullptr){
        return nullptr;
    }
    else{
        NodePedido *res = head;
        head = head->getNext();
        size--;
        return res;
    }
}
NodePedido *PilaPedido::peek(){
    return head;
}
int PilaPedido::getSize() const{
    return this->size;
}
std::ostream& operator<<(std::ostream &out, const PilaPedido &pila){
    NodePedido *current = pila.head;
    out << "HEAD: ";
    while(current != nullptr){
        out << "[" << current->getData() << "] -> " << "\n";
        current = current->getNext();
    }
    out << "NULL" << std::endl;
    return out;
}