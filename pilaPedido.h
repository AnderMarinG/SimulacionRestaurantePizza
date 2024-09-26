#ifndef PILAPEDIDO_H
#define PILAPEDIDO_H

#include "nodePedido.h"
#include <iostream>
#include <stdexcept>

class PilaPedido {
    private:
        //Atributos
        NodePedido *head;
        int size;
    public:
        //Constructor
        PilaPedido();

        //Destructor
        ~PilaPedido();

        //manipulación
        void push(const Pedido data);
        NodePedido *pop();
        NodePedido *peek();
        int getSize() const;

        //Sobrecarga del operador <<
        friend std::ostream& operator<<(std::ostream &out, const PilaPedido &lista);
};
#endif