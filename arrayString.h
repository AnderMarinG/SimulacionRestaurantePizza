#ifndef ARRAYSTRING_H
#define ARRAYSTRING_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

class ArrayString{
    private:
        //atributos
        int MAX_SIZE;
        std::string *elementos;
        int size;
    public:
        //constructores
        ArrayString();
        ArrayString(int n);

        //destructor
        ~ArrayString();
      
        //manipulación
        int getSize() const;
        void insert(std::string string1);
        std::string get(int index) const;

        //Método para leer un archivo y meter los string al array
        void leerArchivo(const std::string &nombreArchivo);

        //Método para obtener un string aleatorio del array
        std::string getAleatorio() const;
};
#endif