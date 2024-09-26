#include "nodePedido.h"
NodePedido::NodePedido() : data(Pedido()){}
NodePedido::NodePedido(const Pedido &data) : data(data), next(nullptr){}
bool NodePedido::isEmpty() const{
    if(data.getTipoPizza() == 0){
        return true;
    }
    else{
        return false;
    }
}
Pedido NodePedido::getData() const{
    return data;
}

NodePedido *NodePedido::getNext() const{
    return next;
}
void NodePedido::setData(const Pedido &data){
    this->data = data;
}
void NodePedido::setNext(NodePedido *nuevoNext){
    this->next = nuevoNext;
}