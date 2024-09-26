#include "colaPedido.h"
ColaPedido::ColaPedido(){
    head = nullptr;
    size = 0;
}
ColaPedido::~ColaPedido(){
    NodePedido *current = head;
    while(current != nullptr){
        NodePedido *temp = current;
        current = current->getNext();
        delete temp;
    }
}
void ColaPedido::enqueue(const Pedido data){
    NodePedido *newNode = new NodePedido(data);
    if(head == nullptr){
        head = newNode;
    }
    else{
        NodePedido *current = head;
        while(current->getNext() != nullptr){
            current = current->getNext();
        }
        current->setNext(newNode);
    }
    size++;
}
NodePedido *ColaPedido::dequeue(){
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
NodePedido *ColaPedido::peek(){
    return head;
}
int ColaPedido::getSize() const{
    return size;
}
std::ostream& operator<<(std::ostream &out, const ColaPedido &lista) {
    NodePedido *current = lista.head;
    out << "HEAD: ";
    while(current != nullptr){
        out << "[" << current->getData() << "] -> " << "\n";
        current = current->getNext();
    }
    out << "NULL" << std::endl;
    return out;
}