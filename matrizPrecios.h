#ifndef MATRIZPRECIOS_H
#define MATRIZPRECIOS_H

#include <iostream>

class MatrizPrecios{
    private:
        //Atributos
        int rows;
        int cols;
        int *elements;
    public:
        //Constructor
        MatrizPrecios();

        //Destructor
        ~MatrizPrecios();

        //Manipulación
        void insert(const int data, int i, int j);

        //Imprimir matriz
        void mostrar() const;
};
#endif