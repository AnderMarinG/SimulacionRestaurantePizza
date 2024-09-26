#ifndef NODECLIENTE_H
#define NODECLIENTE_H

#include "cliente.h"

class NodeCliente{
    private:
        //atributo
        Cliente data;
    public:
        //constructores
        NodeCliente(const Cliente &data);
        NodeCliente();

        //getter
        Cliente getData() const;

        //setter
        void setData(const Cliente &data);
};
#endif