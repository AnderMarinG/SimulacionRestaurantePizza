#ifndef COLAPEDIDO_H
#define COLAPEDIDO_H

#include "nodePedido.h"
#include <iostream>
#include <stdexcept>

class ColaPedido{
    private:
        //Atributos
        NodePedido *head;
        int size;
    public:
        //Constructor
        ColaPedido();

        //Destructor
        ~ColaPedido();

        //Manipulacion
        void enqueue(const Pedido data);
        NodePedido *dequeue();
        NodePedido *peek();

        //Getter
        int getSize() const;

        // Sobrecarga del operador <<
        friend std::ostream& operator<<(std::ostream &out, const ColaPedido &cola);
};
#endif