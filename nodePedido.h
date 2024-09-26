#ifndef NODEPEDIDO_H
#define NODEPEDIDO_H

#include "pedido.h"

class NodePedido {
    private:
        //Atributos
        Pedido data;
        NodePedido *next;
    public:
        //Constructores
        NodePedido();
        NodePedido(const Pedido &data);

        //Manipulación
        bool isEmpty() const;

        //getters-setters
        Pedido getData() const;
        NodePedido *getNext() const;
        void setData(const Pedido &data);
        void setNext(NodePedido *next);
};
#endif