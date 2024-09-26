#ifndef ARRAYCLIENTES_H
#define ARRAYCLIENTES_H

#include "nodeCliente.h"

class ArrayClientes{
    private:
        //Atributos
        int MAX_SIZE;
        NodeCliente *elements;
        int size;
    public:
        //constructor
        ArrayClientes();

        //destructor
        ~ArrayClientes();

        //manipulación
        void insertar(const Cliente &data);
        NodeCliente get(int index) const;

        //getter
        int getSize() const;

        //método para listar los elementos
        void listar() const;
};
#endif